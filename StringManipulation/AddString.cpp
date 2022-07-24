// Problem: https://leetcode.com/problems/add-strings/

#include<string>

using namespace std;

class AddString {	
public:            
    string addStrings(const string& num1, const string& num2) {       
       string num = "";
       int carry_over = 0;
       int i = num1.size() - 1;
       int j = num2.size() - 1;
       while (i >= 0  || j >= 0) {
         int sum = carry_over;
         if (i >= 0) sum += (num1[i] - '0');                                   
         if (j >= 0) sum += (num2[j] - '0');                                            
         carry_over = sum/10;
         sum = sum % 10;
         num = to_string(sum) + num;  
         --i;
         --j;
       }
       if (carry_over > 0) num = std::string("1") + num;                    
       return num;        
    }
};