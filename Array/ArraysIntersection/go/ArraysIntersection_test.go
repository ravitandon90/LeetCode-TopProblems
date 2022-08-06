package _go

import (
	"reflect"
	"testing"
)

func TestArraysIntersection(t *testing.T) {
	type args struct {
		arr1 []int
		arr2 []int
		arr3 []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "Test1",
			args: args{
				arr1: []int{1, 2, 3, 4, 5},
				arr2: []int{1, 2, 5, 7, 9},
				arr3: []int{1, 3, 4, 5, 8},
			},
			want: []int{1, 5},
		},
		{
			name: "Test2",
			args: args{
				arr1: []int{1, 2, 3, 4, 8},
				arr2: []int{1, 2, 4, 7, 8},
				arr3: []int{1, 2, 3, 4, 7, 8},
			},
			want: []int{1, 2, 4, 8},
		},
		{
			name: "Test3",
			args: args{
				arr1: []int{1, 2},
				arr2: []int{3, 4},
				arr3: []int{5, 6},
			},
			want: []int{},
		},
		{
			name: "Test4",
			args: args{
				arr1: []int{1, 2, 3},
				arr2: []int{1, 2, 3},
				arr3: []int{1, 2, 3},
			},
			want: []int{1, 2, 3},
		},
		{
			name: "Test5",
			args: args{
				arr1: []int{1, 2, 3, 4, 5},
				arr2: []int{-1, 1},
				arr3: []int{0, 1, 2},
			},
			want: []int{1},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := ArraysIntersection(tt.args.arr1, tt.args.arr2, tt.args.arr3); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("ArraysIntersection() = %v, want %v", got, tt.want)
			}
			if got := ArraysIntersection2(tt.args.arr1, tt.args.arr2, tt.args.arr3); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("ArraysIntersection()2 = %v, want %v", got, tt.want)
			}
		})
	}
}
