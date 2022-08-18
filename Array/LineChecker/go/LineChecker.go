package _go

// checkStraightLine compare slopes of each point from the first point to the rest of the points.
// Time complexity: O(n)
// Space complexity: O(1)
func checkStraightLine(coordinates [][]int) bool {
	x1, y1 := coordinates[0][0], coordinates[0][1]
	x2, y2 := coordinates[1][0], coordinates[1][1]

	dy := y2 - y1
	dx := x2 - x1

	for i := 2; i < len(coordinates); i++ {
		x, y := coordinates[i][0], coordinates[i][1]
		if dy*(x-x1) != dx*(y-y1) {
			return false
		}
	}
	return true
}
