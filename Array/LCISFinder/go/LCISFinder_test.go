package _go

import (
	"testing"
)

func Test_findLengthOfLCIS(t *testing.T) {
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
				nums: []int{1, 3, 5, 4, 7},
			},
			want: 3,
		},
		{
			name: "Test 2",
			args: args{
				nums: []int{1, 3, 5, 7, 9, 11, 13, 15},
			},
			want: 8,
		},
		{
			name: "Test 3",
			args: args{
				nums: []int{1, 1, 1, 1, 1},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := findLengthOfLCIS(tt.args.nums); got != tt.want {
				t.Errorf("findLengthOfLCIS() = %v, want %v", got, tt.want)
			}
			if got := findLengthOfLCIS2(tt.args.nums); got != tt.want {
				t.Errorf("findLengthOfLCIS2() = %v, want %v", got, tt.want)
			}
		})
	}
}
