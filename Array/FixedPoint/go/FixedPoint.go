package _go

// fixedPoint iterate through the array and check index = value
// Time: O(n)
// space: O(1)
func fixedPoint(nums []int) int {
	for i, v := range nums {
		if i == v {
			return v
		}
	}
	return -1
}

// fixedPoint2 continue searching if you found the num
// Time: O(log n)
// space: O(1)
func fixedPoint2(nums []int) int {
	low, high, mid, ans := 0, len(nums)-1, 0, -1
	for low <= high {
		mid = low + (high-low)/2
		if nums[mid] == mid {
			ans = mid
			high = mid - 1
		} else if nums[mid] > mid {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return ans
}
