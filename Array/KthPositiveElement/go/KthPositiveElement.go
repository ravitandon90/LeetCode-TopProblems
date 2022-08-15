package _go

// findKthPositive inc k if there is any missing number or less than k
// TimeComplexity: O(n)
// SpaceComplexity: O(1)
func findKthPositive(arr []int, k int) int {
	for _, v := range arr {
		if v <= k {
			k++
		} else {
			break
		}
	}
	return k
}

// findKthPositive2 at any index number of missing values = current value at index - index - 1, now you can binary search
// example: 2 3 4 7 11 k =5, max right should be 5 but there is 11, diff = 11 - 5 = 6, which means 6 number is missing in the array, go left
// example: 1 2 3 4 k=2, max right should be 2 but there is 4, diff = 4 - 4 = 0, which means 0 number is missing in the array, go right
// TimeComplexity: O(logn)
// SpaceComplexity: O(1)
func findKthPositive2(arr []int, k int) int {
	l, r := 0, len(arr)-1
	for l <= r {
		mid := l + (r-l)/2
		if arr[mid]-mid > k {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return k + l
}
