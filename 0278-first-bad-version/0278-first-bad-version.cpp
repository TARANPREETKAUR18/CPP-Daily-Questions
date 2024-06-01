// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long lo = -1, hi = n;
        while(lo + 1 < hi) {
            long long mid = lo + ((hi - lo) / 2);
            if (isBadVersion(mid)) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        return hi;
    }
};