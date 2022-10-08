package Array

import (
	"fmt"
	"sort"
)

func main() {
	arr := []int{6, 4, 8, 2, 10}
	K := 2

	sort.Ints(arr)
	fmt.Println("K'th smallest element is ", arr[K-1])
}
