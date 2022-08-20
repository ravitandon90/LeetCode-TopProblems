package _go

// merge iterate both array and merge them, if nums1 is greater, append after nums2 and vice versa
// Time Complexity: O(n)
// Space Complexity: O(1)
func merge(nums1 []int, m int, nums2 []int, n int) {
	ans := make([]int, m+n)
	i, j, k := 0, 0, 0
	for i < m && j < n {
		if nums1[i] < nums2[j] {
			ans[k] = nums1[i]
			i++
		} else {
			ans[k] = nums2[j]
			j++
		}
		k++
	}
	for i < m {
		ans[k] = nums1[i]
		i++
		k++
	}
	for j < n {
		ans[k] = nums2[j]
		j++
		k++
	}
	copy(nums1, ans)
	ans = nil
}
