// Problem: https://leetcode.com/problems/intersection-of-three-sorted-arrays/

#include <unordered_set>
#include <vector>

using namespace std;

class ArraysIntersection {
public:
    vector<int> arraysIntersection(vector<int>& arr1, 
                                   vector<int>& arr2, 
                                   vector<int>& arr3) {
        vector<int> result;
        unordered_set<int> s1;
        unordered_set<int> s2;        
        for (int elem : arr1) s1.insert(elem);
        for (int elem : arr2) s2.insert(elem);
        for (int elem : arr3) {
            if (s1.find(elem) != s1.end() && s2.find(elem) != s2.end()) {
                result.push_back(elem);
            }
        }
        return result;
    }
};