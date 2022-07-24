#include<string>
#include<stack>

using namespace std;

class CrawlerLogFolder {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folder_stack;
        int num_operations = 0;
        for (int index = 0; index < logs.size(); ++index) {
            string op = getOperation(logs[index]);
            if (op == ".") continue;
            if (op == "..") {
                if (not folder_stack.empty()) folder_stack.pop();
                continue;
            }
            folder_stack.push(op);
        }
        return folder_stack.size();
    }

private:
    string getOperation(string str) {
        size_t pos = str.find('/');
        // Note: pos is len here.
        return str.substr(0, pos);
    }
};