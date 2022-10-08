package String

import "fmt"
import "strings"

func main() {
	var str string = "Earth is not flat"
	var subStr string = "lat"

	if strings.Contains(str, subStr) == true {
		fmt.Printf("String (%s) contains sub-string (%s)", str, subStr)
	} else {
		fmt.Printf("String (%s) does not contains substring (%s)", str, subStr)
	}
}
