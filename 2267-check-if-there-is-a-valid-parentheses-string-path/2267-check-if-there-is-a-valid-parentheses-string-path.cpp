class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        vector<bitset<101>> dp;
        int r = grid.size(), c = grid[0].size();
        if(grid[0][0] != '(') return false;
        dp.assign(c, bitset<101>()); dp[0][0] = 1;
        for(int i = 0; i < r; i++){
            if (grid[i][0] == '(') dp[0] <<= 1;
            else dp[0] >>= 1;
            for(int j = 1; j < c; j++){
                dp[j] |= dp[j-1];
                if (grid[i][j] == '(') dp[j] <<= 1;
                else dp[j] >>= 1;
            }
        }
        return dp[c-1][0];
    }
};