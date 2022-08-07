package _go

import (
	"testing"
)

func Test_numIdenticalPairs(t *testing.T) {
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
				nums: []int{1, 2, 3, 1, 1, 3},
			},
			want: 4,
		},
		{
			name: "Test 2",
			args: args{
				nums: []int{1, 1, 1, 1},
			},
			want: 6,
		},
		{
			name: "Test 3",
			args: args{
				nums: []int{1, 2, 3},
			},
			want: 0,
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
				nums: []int{1},
			},
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := numIdenticalPairs(tt.args.nums); got != tt.want {
				t.Errorf("numIdenticalPairs() = %v, want %v", got, tt.want)
			}
			if got := numIdenticalPairs2(tt.args.nums); got != tt.want {
				t.Errorf("numIdenticalPairs()2 = %v, want %v", got, tt.want)
			}
			if got := numIdenticalPairs3(tt.args.nums); got != tt.want {
				t.Errorf("numIdenticalPairs()3 = %v, want %v", got, tt.want)
			}
		})
	}
}
