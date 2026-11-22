class Solution {
public:
    bool checkString(string s) {
        int count_a = count(begin(s), end(s), 'a');
        // the first count_a characters must all be 'a'
        for (int i = 0; i < count_a; i++) {
            if (s[i] != 'a') return false;
        }
        return true;
    }
};