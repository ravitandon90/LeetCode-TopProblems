package _go

import (
	"testing"
)

func Test_isMonotonic(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			name: "Test 1",
			args: args{
				nums: []int{1, 2, 2, 3},
			},
			want: true,
		},
		{
			name: "Test 2",
			args: args{
				nums: []int{6, 5, 4, 4},
			},
			want: true,
		},
		{
			name: "Test 3",
			args: args{
				nums: []int{1, 3, 2},
			},
			want: false,
		},
		{
			name: "Test 4",
			args: args{
				nums: []int{5},
			},
			want: true,
		},
		{
			name: "Test 5",
			args: args{
				nums: []int{},
			},
			want: true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := isMonotonic(tt.args.nums); got != tt.want {
				t.Errorf("isMonotonic() = %v, want %v", got, tt.want)
			}
			if got := isMonotonic2(tt.args.nums); got != tt.want {
				t.Errorf("isMonotonic()2 = %v, want %v", got, tt.want)
			}
		})
	}
}
