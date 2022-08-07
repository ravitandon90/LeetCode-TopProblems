package _go

import (
	"testing"
)

func Test_findMaxConsecutiveOnes(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Test 1",
			args: args{
				nums: []int{1, 1, 0, 1, 1, 1},
			},
			want: 3,
		},
		{
			name: "Test 2",
			args: args{
				nums: []int{0, 1, 0, 1, 1, 1, 1},
			},
			want: 4,
		},
		{
			name: "Test 3",
			args: args{
				nums: []int{1, 1, 1, 1, 1, 1, 1},
			},
			want: 7,
		},
		{
			name: "Test 4",
			args: args{
				nums: []int{},
			},
			want: 0,
		},
		{
			name: "Test 5",
			args: args{
				nums: []int{0, 0, 0},
			},
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := findMaxConsecutiveOnes(tt.args.nums); got != tt.want {
				t.Errorf("findMaxConsecutiveOnes() = %v, want %v", got, tt.want)
			}
			if got := findMaxConsecutiveOnes2(tt.args.nums); got != tt.want {
				t.Errorf("findMaxConsecutiveOnes()2 = %v, want %v", got, tt.want)
			}
		})
	}
}
