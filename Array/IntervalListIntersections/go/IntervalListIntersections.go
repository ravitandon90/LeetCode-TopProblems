package _go

// intervalIntersection check the intersection of two interval lines and once it collide, append the overlap to the result
// Time complexity: O(m + n)
// Space complexity: O(m + n)
func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
	m, n := len(firstList), len(secondList)
	i, j := 0, 0
	result := make([][]int, 0)
	for i < m && j < n {
		if intersects(firstList[i], secondList[j]) {
			result = append(result, overlap(firstList[i], secondList[j]))
		}
		if firstList[i][1] < secondList[j][1] {
			i++
		} else {
			j++
		}
	}
	return result
}
func intersects(a, b []int) bool {
	return a[0] <= b[1] && b[0] <= a[1]
}
func overlap(a, b []int) []int {
	return []int{max(a[0], b[0]), min(a[1], b[1])}
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
