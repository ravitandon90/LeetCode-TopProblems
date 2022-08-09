package _go

// isMonotonic brute force solution
// Time complexity: O(n)
// Space complexity: O(1)
func isMonotonic(nums []int) bool {
	if isMonotoneIncreasing(nums) || isMonotoneDecreasing(nums) {
		return true
	}
	return false
}

// isMonotonic2 clean code
// Time complexity: O(n)
// Space complexity: O(1)
func isMonotonic2(nums []int) bool {
	inc, dec := true, true
	for i := 1; i < len(nums); i++ {
		inc = inc && nums[i] >= nums[i-1]
		dec = dec && nums[i] <= nums[i-1]
	}
	return inc || dec
}

func isMonotoneIncreasing(nums []int) bool {
	for i := 1; i < len(nums); i++ {
		if nums[i] < nums[i-1] {
			return false
		}
	}
	return true
}

func isMonotoneDecreasing(nums []int) bool {
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			return false
		}
	}
	return true
}
