package _go

import (
	"testing"
)

func Test_fixedPoint(t *testing.T) {
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
				nums: []int{1, 3, -1, -3, 5, 3, 6, 7},
			},
			want: 6,
		},
		{
			name: "Test 2",
			args: args{
				nums: []int{1, 2, 3},
			},
			want: -1,
		},
		{
			name: "Test 3",
			args: args{
				nums: []int{0, 1, 2, 3, 4},
			},
			want: 0,
		},
		{
			name: "Test 4",
			args: args{
				nums: []int{},
			},
			want: -1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := fixedPoint(tt.args.nums); got != tt.want {
				t.Errorf("fixedPoint() = %v, want %v", got, tt.want)
			}
			if got := fixedPoint2(tt.args.nums); got != tt.want {
				t.Errorf("fixedPoint()2 = %v, want %v", got, tt.want)
			}
		})
	}
}
