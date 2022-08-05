package _go

import (
	"sort"
)

// mark the occurrence of elements in num1 and check if it is present in num2
// Space Complexity: O(n)
// Time Complexity: O(n)
func intersection(nums1 []int, nums2 []int) []int {
	m := make(map[int]bool)
	for _, n := range nums1 {
		m[n] = true
	}
	res := make([]int, 0)
	for _, n := range nums2 {
		if _, ok := m[n]; ok {
			res = append(res, n)
			delete(m, n)
		}
	}
	return res
}

// sort the nums1 and nums2 and then iterate through them
// use two pointer to keep track of the current index in nums1 and nums2
// Space Complexity: O(1)
// Time Complexity: O(nlog(n))
func intersection2(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	res := make([]int, 0)
	i, j := 0, 0
	for i < len(nums1) && j < len(nums2) {
		if nums1[i] == nums2[j] {
			// if the element is already in the result, skip it
			if len(res) > 0 && res[len(res)-1] != nums2[j] || len(res) == 0 {
				res = append([]int{nums1[i]}, res...)
			}
			i++
			j++
		} else if nums1[i] < nums2[j] {
			i++
		} else {
			j++
		}
	}
	return res
}
