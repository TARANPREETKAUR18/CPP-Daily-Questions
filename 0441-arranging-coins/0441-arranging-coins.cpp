class Solution {
public:
    long long isCompleteRow(long long num) {
        return num * (num + 1) / 2;
    }
    long long arrangeCoins(int n) {
        long long lo = 1;
        long long hi = n;
        long long mid;
        while(lo + 1 < hi) {
            mid = lo + floor((hi - lo) /2);
            if(isCompleteRow(mid) <= n) lo = mid;
            else hi = mid;
        }
        // if(lo = -1) return 0;
        return lo;
    }
};