class Solution {
public:
    bool recc(string &s, string t, int i, int j) {
        if(i==s.size()) return true;
        if(j == t.size()) return false;
        if(s[i]==t[j]) return recc(s, t, i+1, j+1);
        return recc(s, t, i, j+1);
    }
    // aa, aab
    bool isSubsequence(string s, string t) {
        return recc(s, t, 0, 0);
    }
};