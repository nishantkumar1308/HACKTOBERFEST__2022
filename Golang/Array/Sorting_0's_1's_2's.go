package Array

import "fmt"

func main() {
	sort([]int{2, 0, 2, 1, 1, 0, 0, 2, 1})
}

func sort(arr []int) {
	low := 0
	mid := 0
	high := len(arr) - 1

	for mid <= high {

		switch arr[mid] {
		case 0:
			arr[low], arr[mid] = arr[mid], arr[low]
			low++
			mid++
		case 1:
			mid++
		case 2:
			arr[mid], arr[high] = arr[high], arr[mid]
			high--
		}
	}
	fmt.Println(arr)
}
