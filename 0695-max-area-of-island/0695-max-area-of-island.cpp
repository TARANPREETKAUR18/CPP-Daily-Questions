class Solution {
public:

    int dfs(int i, int j, int m, int n, vector<vector<int>>& g){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(g[i][j]==0) return 0;
        g[i][j]=0;

        return 1 + dfs(i+1, j, m, n, g) +
        dfs(i-1, j, m, n, g) +
        dfs(i, j-1, m, n, g) +
        dfs(i, j+1, m, n, g);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int ans = dfs(i, j, m, n, grid);
                    cnt = max(cnt, ans);
                }
            }
        }

        return cnt;
    }
};