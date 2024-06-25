class Solution {
public:
    
//      1, 2, 3                1,    5, 5
//     -2, -1, 10              1,    2, 2
//     -1, -1, -100           100, 100, 1
    
//     BS(upper & lower bound) - monotonicity & range
//     recursion - sub-problems
//     dp(long sighted) - overlapping sub-problems
//     greedy(short sighted) - garantee local-maxima/local-minima
//     dfs - trying all paths & going in depth
//     bfs - level order traversal when similar events take place at same point of time
//     backtracking - traverse all paths + store it -> (push & pop / use & throw)
       
    // push & pop - heap sort(for min heap)
    
    int dfs (vector<vector<int>> &matrix, int row, int prevCol, vector<vector<int>> &dp) {
        
        int minSum = 1e8;
        if (row==matrix.size()) {
            return 0;
        }
        
        if (dp[row][prevCol+1]!=-10001) return dp[row][prevCol+1];
        
        if (prevCol==-1) {
            for (int i=0; i<matrix.size(); i++) {
                int currSum = dfs(matrix, row+1, i, dp) + matrix[row][i];
                minSum = min(minSum, currSum);
            }
        }
        
        else {
            for (int i=-1; i<2; i++) {
                int newCol = i + prevCol;
                if(newCol>=0 && newCol<matrix.size()) {
                    int currSum = dfs(matrix, row+1, newCol, dp) + matrix[row][newCol];
                    minSum = min(minSum, currSum);
                }
            }
        }
        return dp[row][prevCol+1] = minSum;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(100, vector<int>(101, -10001));
        int preCol = -1;
        return dfs(matrix, 0, preCol, dp);
    }
};
















