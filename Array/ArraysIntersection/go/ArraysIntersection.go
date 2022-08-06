package _go

// ArraysIntersection Brute Force Solution: Index the occurences of all the array in hashmap and then check the intersection
// Time complexity: O(n)
// Space complexity: O(n)
func ArraysIntersection(arr1 []int, arr2 []int, arr3 []int) []int {
	result := make([]int, 0)
	m := make(map[int]int)
	for _, v := range arr1 {
		m[v]++
	}
	for _, v := range arr2 {
		m[v]++
	}
	for _, v := range arr3 {
		m[v]++
		if m[v] == 3 {
			result = append(result, v)
		}
	}
	return result
}

// ArraysIntersection2 As the array is already sorted we can take the benefit of it, use three pointer to mark the index and compare the value
// Time complexity: O(n)
// Space complexity: O(1)
func ArraysIntersection2(arr1 []int, arr2 []int, arr3 []int) []int {
	result := make([]int, 0)
	i, j, k := 0, 0, 0
	for i < len(arr1) && j < len(arr2) && k < len(arr3) {
		v1, v2, v3 := arr1[i], arr2[j], arr3[k]
		if v1 == v2 && v2 == v3 {
			result = append(result, v1)
			i++
			j++
			k++
		} else {
			incI, incJ, incK := 0, 0, 0
			if v1 < v2 || v1 < v3 {
				incI = 1
			}
			if v2 < v1 || v2 < v3 {
				incJ = 1
			}
			if v3 < v1 || v3 < v2 {
				incK = 1
			}
			i += incI
			j += incJ
			k += incK
		}
	}
	return result
}
