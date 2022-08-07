package _go

// FindMaxConsecutiveOnes
// Time complexity: O(n)
// Space complexity: O(1)
func findMaxConsecutiveOnes(nums []int) int {
	n := len(nums)
	count, ans := 0, 0
	for i := 0; i < n; i++ {
		if nums[i] == 1 {
			count++
		} else {
			count = 0
		}
		ans = max(ans, count)
	}
	return ans
}

// FindMaxConsecutiveOnes2 Simple create a number by adding 1 and update when it is 0
// Time complexity: O(n)
// Space complexity: O(1)
func findMaxConsecutiveOnes2(nums []int) int {
	sum, ans := 0, 0
	for _, num := range nums {
		sum = sum*num + num
		ans = max(ans, sum)
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
