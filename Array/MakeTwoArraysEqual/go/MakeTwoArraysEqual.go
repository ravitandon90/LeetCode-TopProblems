package _go

// canBeEqual store frequency of each element in map and check if two arrays are equal
// Time Complexity: O(n)
// Space Complexity: O(n)
func canBeEqual(target []int, arr []int) bool {
	m := make(map[int]int)
	for _, v := range target {
		m[v]++
	}
	for _, v := range arr {
		m[v]--
		if m[v] < 0 {
			return false
		}
	}
	return true
}
