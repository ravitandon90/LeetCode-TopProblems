// Problem: https://leetcode.com/problems/employee-importance/

#include<unordered_map>
#include<vector>

using namespace std;

// Definition for Employee.
struct Employee {
    int id;
    int importance;
    vector<int> subordinates;
};

class EmployeeImportance {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map <int, Employee*> h_map;
        for (int i = 0; i < employees.size(); ++i) {
            Employee* employee = employees[i];
            h_map[employee->id] = employee;
        }
        return dfs(h_map, id);
    }

    int dfs(const unordered_map <int, Employee*>& h_map, int id) {
        Employee* employee = h_map.at(id);
        int importance = employee->importance;
        for (int i = 0; i < employee->subordinates.size(); ++i) {
            importance += dfs(h_map, employee->subordinates[i]);
        }
        return importance;
    }
};