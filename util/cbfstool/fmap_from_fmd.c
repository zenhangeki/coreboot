/* fmap_from_fmd.c, tool to distill flashmap descriptors into raw FMAP sections */
/* SPDX-License-Identifier: GPL-2.0-only */

#include "fmap_from_fmd.h"

#include "common.h"

#include <assert.h>
#include <string.h>

static bool fmap_append_fmd_node(struct fmap **flashmap,
				const struct flashmap_descriptor *section,
						unsigned absolute_watermark) {
	uint16_t flags = 0;
	if (strlen(section->name) >= FMAP_STRLEN) {
		ERROR("Section name ('%s') exceeds %d character FMAP format limit\n",
						section->name, FMAP_STRLEN - 1);
		return false;
	}

	absolute_watermark += section->offset;

	if (section->flags.f.preserve)
		flags |= FMAP_AREA_PRESERVE;

	if (fmap_append_area(flashmap, absolute_watermark, section->size,
					(uint8_t *)section->name, flags) < 0) {
		ERROR("Failed to insert section '%s' into FMAP\n",
								section->name);
		return false;
	}

	fmd_foreach_child(subsection, section) {
		if (!fmap_append_fmd_node(flashmap, subsection,
							absolute_watermark))
			return false;
	}

	return true;
}

struct fmap *fmap_from_fmd(const struct flashmap_descriptor *desc)
{
	assert(desc);
	assert(desc->size_known);

	if (strlen(desc->name) >= FMAP_STRLEN) {
		ERROR("Image name ('%s') exceeds %d character FMAP header limit\n",
						desc->name, FMAP_STRLEN - 1);
		return NULL;
	}

	struct fmap *fmap = fmap_create(desc->offset_known ? desc->offset : 0,
					desc->size, (uint8_t *)desc->name);
	if (!fmap) {
		ERROR("Failed to allocate FMAP header\n");
		return fmap;
	}

	fmd_foreach_child(real_section, desc) {
		if (!fmap_append_fmd_node(&fmap, real_section, 0)) {
			fmap_destroy(fmap);
			return NULL;
		}
	}

	return fmap;
}
