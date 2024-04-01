class Solution {
public:
    int lengthOfLastWord(string s) {
        int maxLen = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] != ' ') maxLen++;
            else if(s[i] == ' ' && maxLen != 0) return maxLen;
        }
        return maxLen;
    }
};