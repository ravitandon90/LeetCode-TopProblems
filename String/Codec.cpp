// Problem-Link: https://leetcode.com/problems/encode-and-decode-strings/

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

#include<string>
#include<stack>
#include<vector>

using namespace std;

class Codec {
public:
	// Encodes a list of strings to a single string.
	string encode(vector<string>& strs) {
		string encoded = "";
		for (int i = 0; i < strs.size(); ++i) {
			for (int j = 0; j < strs.at(i).size(); ++j) {
				char curr = strs.at(i).at(j);
				if (curr == sep || curr == esc) {
					encoded.append(1, esc);
					encoded.append(1, curr);
				} else {
					encoded.append(1, curr);
				}
			}
			encoded.append(1, sep);
		}
		return encoded;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		stack<char> st;
		vector<string> decoded;
		string curr_str = "";
		for (int i = 0; i < s.size(); ++i) {
			char curr = s.at(i);
			if (curr == esc) {
				if (st.size() == 0) {
					st.push(curr);
				} else {
					st.pop();
					curr_str.append(1, curr);
				}
			} else if (curr == sep) {
				if (st.size() == 0) {
					decoded.push_back(curr_str);
					curr_str.clear();
				} else {
					st.pop();
					curr_str.append(1, curr);
				}
			} else {
				curr_str.append(1, curr);
			}
		}
		if (curr_str.size() > 0) decoded.push_back(curr_str);
		return decoded;
	}

private:
	char esc = '-';
	char sep = ':';
};
