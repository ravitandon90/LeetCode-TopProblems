#include<vector>

using namespace std;

class NumberOfCandies {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max = 0;
		vector<bool> out_vec;
		for (int index = 0; index < candies.size(); ++index) {
			if (max < candies[index]) max = candies[index];
		}
		for (int index = 0; index < candies.size(); ++index) {
			out_vec.push_back((candies[index] + extraCandies >= max));
		}
		return out_vec;
	}
};