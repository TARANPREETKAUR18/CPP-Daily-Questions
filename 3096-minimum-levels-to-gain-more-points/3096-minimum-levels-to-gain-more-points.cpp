class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int totalScore = 0;
        for(int i = 0; i < n; i++) {
            if(possible[i] == 0) possible[i] = -1;
            totalScore += possible[i];
        }
        int danielScore = 0;
        for(int i = 0; i < n - 1; i++) {
            danielScore += possible[i];
            if(danielScore > totalScore - danielScore) return i + 1;
        }
        return -1;
    }
};