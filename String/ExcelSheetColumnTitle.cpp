#include<string>

using namespace std;

class ExcelSheetColumnTitle {
public:
    string convertToTitle(int columnNumber) {
        string outStr = "";
        int num = columnNumber;
        while (num > 0) {
            int rem = num % 26;
            if (rem == 0) rem = 26;
            char ch = 'A' + (rem -1);            
            outStr = ch + outStr;  
            --num;
            num /= 26;
        }
        return outStr;
    }
};