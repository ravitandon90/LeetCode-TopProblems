package _go

import (
	"sort"
)

// hIndex store the index for all of citation, if greater than length inc else inc the value one
// Time complexity: O(n)
// Space complexity: O(n)
func hIndex(citations []int) int {
	bucket := make(map[int]int, len(citations)+1)
	for _, v := range citations {
		if v > len(citations) {
			bucket[len(citations)]++
		} else {
			bucket[v]++
		}
	}
	count := 0
	for i := len(citations); i >= 0; i-- {
		count += bucket[i]
		if count >= i {
			return i
		}
	}
	return 0
}

// hIndex2 sort the citation and binary search
// Time complexity: O(nlog(n))
// Space complexity: O(1)
func hIndex2(citations []int) int {
	low, high := 0, len(citations)-1
	sort.Ints(citations)
	for low <= high {
		mid := low + (high-low)/2
		if citations[mid] >= len(citations)-mid {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return len(citations) - low
}
