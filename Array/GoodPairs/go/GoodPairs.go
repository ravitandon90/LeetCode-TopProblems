package _go

import (
	"sort"
)

// GoodPairs check for each pair
// Time complexity: O(n)
// Space complexity: O(1)
func numIdenticalPairs(nums []int) int {
	count := 0
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i] == nums[j] {
				count++
			}
		}
	}
	return count
}

// numIdenticalPairs2 store the indexes in hashmap
// Time complexity: O(n)
// Space complexity: O(n)
func numIdenticalPairs2(nums []int) int {
	m := make(map[int]int)
	for _, v := range nums {
		m[v]++
	}
	count := 0
	for _, v := range m {
		count += v * (v - 1) / 2
	}
	return count
}

// numIdenticalPairs3 sort the array and calculate the pair
// Time complexity: O(nlog(n))
// Space complexity: O(1)
func numIdenticalPairs3(nums []int) int {
	count, ans := 0, 0
	sort.Ints(nums)
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			count++
		} else {
			ans += count * (count + 1) / 2
			count = 0
		}
	}
	ans += count * (count + 1) / 2
	return ans
}
