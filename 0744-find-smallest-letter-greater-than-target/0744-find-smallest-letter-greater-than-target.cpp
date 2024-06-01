class Solution {
public:
     bool isGreater(char alpha, char target) {
        return alpha > target;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = -1, hi = letters.size(), mid;
        while(lo + 1 < hi) {
            mid = lo + floor((hi - lo) / 2);
            if(isGreater(letters[mid], target)) hi = mid;
            else lo = mid;
        }
        if(hi == letters.size() || letters[hi] < target) return letters[0];
        return letters[hi];
    }
};