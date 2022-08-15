package _go

// typically check the continuos increasing subarray and store the max in a third var
// Time complexity: O(n)
// Space complexity: O(1)
func findLengthOfLCIS(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}
	ans, count := 1, 1
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] < nums[i+1] {
			count++
			ans = max(ans, count)
		} else {
			count = 1
		}
	}
	return ans
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// just used an extra storage to store all those states
// Time complexity: O(n)
// Space complexity: O(n)
func findLengthOfLCIS2(nums []int) int {
	if len(nums) <= 1 {
		return len(nums)
	}
	dp := make([]int, len(nums))
	dp[0] = 1
	ans := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] > nums[i-1] {
			dp[i] = dp[i-1] + 1
		} else {
			dp[i] = 1
		}
		ans = max(ans, dp[i])
	}
	return ans
}
