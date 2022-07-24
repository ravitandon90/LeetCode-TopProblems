// Problem: https://leetcode.com/problems/first-bad-version/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class FirstBadVersion {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        return firstBadVersionInt(1, n, n);
    }

private:
    int firstBadVersionInt(int s, int e, int n) {
        int mid = max(s, s / 2 + e / 2);
        bool isBad1 = isBadVersion(mid);
        bool isBad2 = isBadVersion(min(n, mid + 1));
        if (not isBad1 && isBad2) return min(n, mid + 1);
        if (isBad1) return firstBadVersionInt(s, mid - 1, n);
        return firstBadVersionInt(mid + 1, e, n);
    }
};