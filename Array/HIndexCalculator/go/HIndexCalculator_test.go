package _go

import (
	"testing"
)

func Test_hIndex(t *testing.T) {
	type args struct {
		citations []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Test 1",
			args: args{
				citations: []int{3, 0, 6, 1, 5},
			},
			want: 3,
		},
		{
			name: "Test 2",
			args: args{
				citations: []int{1, 1, 1, 1},
			},
			want: 1,
		},
		{
			name: "Test 3",
			args: args{
				citations: []int{1, 2, 3},
			},
			want: 2,
		},
		{
			name: "Test 4",
			args: args{
				citations: []int{},
			},
			want: 0,
		},
		{
			name: "Test 5",
			args: args{
				citations: []int{1},
			},
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := hIndex(tt.args.citations); got != tt.want {
				t.Errorf("hIndex() = %v, want %v", got, tt.want)
			}
			if got := hIndex2(tt.args.citations); got != tt.want {
				t.Errorf("hIndex()2 = %v, want %v", got, tt.want)
			}
		})
	}
}
