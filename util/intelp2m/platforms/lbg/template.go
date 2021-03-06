package lbg

type InheritanceTemplate interface {
	GroupNameExtract(line string) (bool, string)
	KeywordCheck(line string) bool
}

// GroupNameExtract - This function extracts the group ID, if it exists in a row
// line      : string from the configuration file
// return
//     bool   : true if the string contains a group identifier
//     string : group identifier
func (platform PlatformSpecific) GroupNameExtract(line string) (bool, string) {
	return platform.InheritanceTemplate.GroupNameExtract(line)
}

// KeywordCheck - This function is used to filter parsed lines of the configuration file and
//                returns true if the keyword is contained in the line.
// line      : string from the configuration file
func (platform PlatformSpecific) KeywordCheck(line string) bool {
	return platform.InheritanceTemplate.KeywordCheck(line)
}
