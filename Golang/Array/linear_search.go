package main

import "fmt"

func main() {
	var arr [5]int
	var item int = 0
	var flag int = 0
	fmt.Printf("Enter array elements: \n")
	for i := 0; i <= 4; i++ {
		fmt.Printf("Elements: arr[%d]: ", i)
		fmt.Scanf("%d", &arr[i])
	}

	fmt.Printf("Enter item: ")
	fmt.Scanf("%d", &item)
	for i := 0; i <= 4; i++ {
		if item == arr[i] {
			flag = 1
			fmt.Printf("Item %d at index %d", item, i)
			break
		}
	}

	if flag == 0 {
		fmt.Printf("Item %d not found in array")
	}
}
