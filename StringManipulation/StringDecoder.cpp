// Problem-Link: https://leetcode.com/problems/decode-string/
#include<string>
#include<stack>

using namespace std;

class StringDecoder {
public:
    string decodeString(string s) {
       string output = "";
       for (int i = 0; i < s.size(); ++i) {
         char curr_ch = s.at(i);
         // Pushing to a stack.
         if (curr_ch == '"') continue;
         // Removing from the stack.
         if (curr_ch == ']') {
             string s_rep;
             // Finding s_rep. 
             while (elems.size() > 0) {
                 char in_ch = elems.top();
                 elems.pop();
                 if (in_ch == '[') break;
                 s_rep.insert(s_rep.begin(), in_ch);
             }
             string num_rep_str;
             while (elems.size() > 0) {
                 char in_ch = elems.top();
                 if (std::isdigit(in_ch)) {
                     num_rep_str.insert(num_rep_str.begin(), in_ch);
                     elems.pop();
                 } else {
                     break;
                 }
             }
             int num_rep = std::stoi(num_rep_str);
             // Adding s_rep to output.
             for (int i = 0; i < num_rep; ++i){
                 for (int j = 0; j < s_rep.size(); ++j){
                     elems.push(s_rep.at(j));
                 }
             }
             continue;
         }
         elems.push(curr_ch);
       }
        while (elems.size() > 0){
            output.insert(output.begin(), elems.top());
            elems.pop();
        }
        return output;
    }
    
 private: 
    stack<char> elems;
};