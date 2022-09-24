package _go

func findMiddleIndex(nums []int) int {
	sum, leftPrefixSum, rightPrefixSum := 0, 0, 0
	for _, num := range nums {
		sum += num
	}
	for i := 0; i < len(nums); i++ {
		rightPrefixSum = sum - leftPrefixSum - nums[i]
		if leftPrefixSum == rightPrefixSum {
			return i
		}
		leftPrefixSum += nums[i]
	}

	return -1
}
