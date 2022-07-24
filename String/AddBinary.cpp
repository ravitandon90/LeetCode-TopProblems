#include<string>

using namespace std;

class AddBinary {
public:
    string addBinary(const string& a, const string& b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry_over = 0;
        while (i >= 0 || j >=0) {
            int sum = carry_over;
            if (i >= 0) sum += (a[i]-'0');
            if (j >= 0) sum += (b[j]-'0');
            carry_over = sum / 2;
            sum = sum % 2;
            result = to_string(sum) + result;      
            --i;
            --j;
        }
        if (carry_over > 0) result = std::string("1") + result;
        return result;
    }
};