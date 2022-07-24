// Problem: https://leetcode.com/problems/interleaving-string/

#include <string>
#include <unordered_map>

using namespace std;

class InterleavingString {
public:
	bool isInterleave(string s1, string s2, string s3) {
		return isInterleaveInt(s3, s1, s2);
	}

	bool isInterleaveInt(string s1, string s2, string s3) {
		if (s1.size() != (s2.size() + s3.size())) return false;
		// S1.size = S2.size + S3.size

		// All characters checked.
		if (s1.size() == 0) return true;

		// One string empty.
		if (s2.size() == 0) return s1 == s3;
		if (s3.size() == 0) return s1 == s2;

		const string key = ToString(s1.size(), s2.size(), s3.size());
		if (memo_map.find(key) != memo_map.end()) return memo_map[key];

		bool found = false;
		// Explore one route.
		if (s1.at(0) == s2.at(0)) {
			found = isInterleaveInt(s1.substr(1), s2.substr(1), s3);
		}

		// Explore other route.
		if (s1.at(0) == s3.at(0)) {
			found = found || isInterleaveInt(s1.substr(1), s2, s3.substr(1));
		}

		memo_map[key] = found;
		return found;
	}

private:
	unordered_map<string, bool> memo_map;

	string ToString(int i, int j, int k) {
		return std::to_string(i) + "," + std::to_string(j) + "," + std::to_string(k);
	}
};