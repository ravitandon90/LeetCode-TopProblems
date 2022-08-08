package _go

// deCompressRLE : iterate through the freq and append to array
// Time: O(n)
// Space: O(n)
func decompressRLElist(nums []int) []int {
	res := make([]int, 0)
	for i := 0; i < len(nums); i += 2 {
		key, value := nums[i], nums[i+1]
		for j := 0; j < key; j++ {
			res = append(res, value)
		}
	}
	return res
}
