// Problem: https://leetcode.com/problems/logger-rate-limiter/

#include<unordered_map>

using namespace std;

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
class Logger {
public:
	/** Initialize your data structure here. */
	Logger() {}

	/** 
	 * Returns true if the message should be printed in the given timestamp, otherwise returns false.
	 * If this method returns false, the message will not be printed. 
	 * The timestamp is in seconds granularity. 
	 */
	bool shouldPrintMessage(int timestamp, string message) {
		if (this->_tstamp.find(message) != this->_tstamp.end()) {
			int old_tstamp = this->_tstamp[message];
			if (timestamp - old_tstamp >= 10) {
				this->_tstamp[message] = timestamp;
				return true;
			}
			return false;
		}
		this->_tstamp[message] = timestamp;
		return true;
	}

private:
	unordered_map<string, int> _tstamp;
};