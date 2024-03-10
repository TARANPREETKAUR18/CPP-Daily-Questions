class Solution {
public:

    void dfs(int i, int j, int m, int n, vector<vector<char>>& g){
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(g[i][j]=='0') return;

        g[i][j]='0';

        dfs(i+1, j, m, n, g);
        dfs(i-1, j, m, n, g);
        dfs(i, j-1, m, n, g);
        dfs(i, j+1, m, n, g);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, m, n, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};