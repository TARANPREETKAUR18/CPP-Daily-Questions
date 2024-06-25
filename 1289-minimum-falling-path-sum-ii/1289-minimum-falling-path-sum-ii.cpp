class Solution {
public:
    int dfs (vector<vector<int>> &matrix, int row, int prevCol, vector<vector<int>> &dp) {
        
        int minSum = 1e8;
        if (row==matrix.size()) {
            return 0;
        }
        
        if (dp[row][prevCol+1]!=-20001) return dp[row][prevCol+1];
        
            for (int i=0; i<matrix.size(); i++) {
                if (i!=prevCol) {
                    int currSum = dfs(matrix, row+1, i, dp) + matrix[row][i];
                    minSum = min(minSum, currSum);
                }
            }
        return dp[row][prevCol+1] = minSum;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(200, vector<int>(201, -20001));
        int preCol = -1;
        return dfs(matrix, 0, preCol, dp);
    }
};