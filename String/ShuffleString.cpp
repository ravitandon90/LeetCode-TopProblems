#include<string>
#include<vector>

using namespace std;

class ShuffleString {
public:
    string restoreString(string s, vector<int>& indices) {
        string output = s;
        for (int index = 0; index < indices.size(); ++index){
            output[indices[index]] = s[index];   
        }        
        return output;
    }
};