package _go

import (
	"testing"
)

func Test_canBeEqual(t *testing.T) {
	type args struct {
		target []int
		arr    []int
	}
	tests := []struct {
		name string
		args args
		want bool
	}{
		{
			name: "Test 1",
			args: args{
				target: []int{1, 2, 3, 4},
				arr:    []int{2, 4, 1, 3},
			},
			want: true,
		},
		{
			name: "Test 2",
			args: args{
				target: []int{1, 2, 3, 4},
				arr:    []int{2, 1, 1, 3},
			},
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := canBeEqual(tt.args.target, tt.args.arr); got != tt.want {
				t.Errorf("canBeEqual() = %v, want %v", got, tt.want)
			}
		})
	}
}
