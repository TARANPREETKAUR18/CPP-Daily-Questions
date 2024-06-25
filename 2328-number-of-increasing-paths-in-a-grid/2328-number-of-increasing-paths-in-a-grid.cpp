class Solution {
public:
    
    long long add(long long A, long long B, long long C=1e9+7) {
        return (A % C + B % C) % C;
    }
    
    int dp[1000][1000];
    vector<int> directionX = {-1, 0, 1, 0};
    vector<int> directionY = {0, -1, 0, 1}; 
    
    bool validStep(int newX, int newY, int oldX, int oldY, vector<vector<int>> &matrix) {
        return newX>=0 && newX<matrix.size() && newY>=0 && newY<matrix[0].size() && matrix[newX][newY] > matrix[oldX][oldY];
    }
    
    int dfs(vector<vector<int>> &matrix, int i, int j) {
        if(dp[i][j]!=-1) return dp[i][j];
        int longestPath = 1;
        for (int X=0; X<4; X++) {
            int newX = directionX[X] + i;
            int newY = directionY[X] + j;
            if (validStep(newX, newY, i, j, matrix)) {
                int currPath = dfs(matrix, newX, newY);
                longestPath = add(currPath, longestPath);
            }
        }
        return dp[i][j] = longestPath;
    }
    
    int countPaths(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int longestPath = 0;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                int currPath = dfs(matrix, i, j);
                longestPath = add(currPath, longestPath);
            }
        }
        return longestPath;
    }
};