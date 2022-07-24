#include<string>
using namespace std;

class IPAddrDefanger {
public:
    string defangIPaddr(string address) {
     string defanged_string = "";     
     for (int index = 0; index < address.size(); ++index) {
        if (address[index] == '.') {            
            defanged_string += "[.]";            
        } else {
            defanged_string += address[index];
        }
     }
     return defanged_string;
    }
};