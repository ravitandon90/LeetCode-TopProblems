// Problem: https://leetcode.com/problems/binary-watch/

#include <string>
#include <vector>

using namespace std;

struct Time {
    Time() : hours(0), minutes(0) {}
    int hours;
    int minutes;
};

class BinaryWatch {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn == 0) return {"0:00"};
        // The first four digits are hours, and the next six are minutes.
        vector<bool> digits;
        digits.resize(10, 0);
        // Encapsulates all the results in this vector.
        vector<string> results;
        // Iteration to get the next vector.
        getNext(digits, 0, turnedOn, results);
        sort(results.begin(), results.end());
        // Return all the results.
        return results;
    }

private:
    void getNext(vector<bool>& digits, int index, int turnedOn, vector<string>& results) {
        if (turnedOn <= 0) return;
        if (index >= 10) return;

        Time time;
        digits[index] = true;
        if (turnedOn == 1) {
            time = getTime(digits);
            if (isValid(time)) results.push_back(toString(time));
        } else {
            getNext(digits, index + 1, turnedOn - 1, results);
        }
        digits[index] = false;
        getNext(digits, index + 1, turnedOn, results);
    }

    Time getTime(vector<bool>& digits) {
        Time t;
        for (int i = 0; i < 4; ++i) {
            if (digits[i]) t.hours += pow(2, 3 - i);
        }
        for (int i = 4; i < 10; ++i) {
            if (digits[i]) t.minutes += pow(2, 9 - i);
        }
        return t;
    }

    bool isValid(const Time& t) {
        if (t.minutes == 0 && t.hours == 0) return false;
        return t.hours < 12 && t.minutes <= 59;
    }

    string toString(const Time& t) {
        string time;
        // Adding hours.
        if (t.hours > 0) time = to_string(t.hours);
        else time = "0";
        // Adding separator.
        time += ":";
        // Adding minutes.
        if (t.minutes >= 0 && t.minutes < 10) time += "0" + to_string(t.minutes);
        else time += to_string(t.minutes);
        return time;
    }
};