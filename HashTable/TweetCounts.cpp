// Problem: https://leetcode.com/problems/tweet-counts-per-frequency/

#include <string>
#include <unordered_map>

using namespace std;

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
class TweetCounts {
public:
    TweetCounts() {}

    void recordTweet(const string& tweetName, int time) {
        t_ts_[tweetName].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(const string& freq, const string& tweetName,
                                           int startTime, int endTime) {
        vector<int> result;
        int delta = endTime - startTime;
        int chunkSize = 1;
        if (freq == "minute") chunkSize = 60;
        else if (freq == "hour") chunkSize = 60 * 60;
        else if (freq == "day") chunkSize = 60 * 60 * 24;
        int numChunks = delta / chunkSize + 1;
        result.resize(numChunks, 0);
        if (t_ts_.find(tweetName) == t_ts_.end()) return result;
        vector<int> ts = t_ts_.at(tweetName);
        for (int timestamp : ts) {
            if (timestamp < startTime || timestamp > endTime) continue;
            int bucket_id = (timestamp - startTime) / chunkSize;
            if (result.size() <= bucket_id) result.resize(bucket_id + 1, 0);
            result[bucket_id]++;
        }
        return result;
    }

private:
    unordered_map<string, vector<int>> t_ts_;
};