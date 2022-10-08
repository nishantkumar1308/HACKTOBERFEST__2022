package Array

import "fmt"

func main() {
	var arr [5]int
	var item int = 0
	var flag int = 0
	var first int = 0
	var last int = 0
	var middle int = 0

	fmt.Printf("Enter array elements: \n")
	for i := 0; i <= 4; i++ {
		fmt.Printf("Elements: arr[%d]: ", i)
		fmt.Scanf("%d", &arr[i])
	}

	fmt.Printf("Enter item: ")
	fmt.Scanf("%d", &item)

	first = 0
	last = 4
	middle = (first + last) / 2

	for first := 0; first <= last; {
		if arr[middle] < item {
			first = middle + 1
		} else if arr[middle] == item {
			flag = 1
			fmt.Printf("Item %d found at index %d", item, middle)
			break
		} else {
			last = middle - 1
		}
		middle = (first + last) / 2
	}

	if flag == 0 {
		fmt.Printf("Item %d not found in array", item)
	}
}
