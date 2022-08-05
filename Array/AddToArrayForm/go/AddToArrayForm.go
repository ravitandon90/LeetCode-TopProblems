package _go

// space complexity: O(n), time complexity: O(n)
// convert the array to integer, add it and convert it back to array
// for large output it can fail, we can use uint64 or big.NewInt type
func addToArrayForm(num []int, k int) []int {
	if k == 0 {
		return num
	}
	var sliceToInt, op int
	sliceToInt, op = 0, 1

	for i := len(num) - 1; i >= 0; i-- {
		sliceToInt += op * num[i]
		op *= 10
	}
	newNum := sliceToInt + k

	var intToSlice []int

	for newNum > 0 {
		intToSlice = append([]int{newNum % 10}, intToSlice...)
		newNum /= 10
	}

	return intToSlice
}

// space complexity: O(1), time complexity: O(n)
// calculate the carry and add it to the array
// 274 + 181 -> 2,7,185 -> 2,7+18,5 -> 2+2,5,5 = 455
func addToArrayForm2(num []int, k int) []int {
	if k == 0 {
		return num
	}
	for i := len(num) - 1; i >= 0; i-- {
		num[i] += k
		k = num[i] / 10
		num[i] %= 10
	}
	for k > 0 {
		num = append([]int{k % 10}, num...)
		k /= 10
	}
	return num
}
