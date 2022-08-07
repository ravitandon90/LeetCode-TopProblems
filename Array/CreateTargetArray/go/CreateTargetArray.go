package _go

// Time: O(n^2) as copy is O(n)
// Space: O(1)
func createTargetArray(nums []int, index []int) []int {
	res := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		if index[i] <= i {
			copy(res[index[i]+1:], res[index[i]:])
		}
		res[index[i]] = nums[i]
	}
	return res
}
