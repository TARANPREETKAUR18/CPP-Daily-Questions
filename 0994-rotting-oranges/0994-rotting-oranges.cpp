class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>> &grid) {
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int minutes = -1;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                }
                
                if(grid[i][j]==1) {
                    count++;
                }
            }
        }
        
        if(!count) return 0;
        
        vector<int> directionX = {0, +1, 0, -1};
        vector<int> directionY = {-1, 0, +1, 0};
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                pair<int, int> temp = q.front();
                q.pop();
                
                for(int i=0; i<4; i++) {
                    int newX = directionX[i] + temp.first;
                    int newY = directionY[i] + temp.second;
                    
                    if(isValid(newX, newY, grid)) {
                        count--;
                        grid[newX][newY]=2;
                        q.push({newX, newY});
                    }
                }
            }
            
            minutes++;
        }
        
        if(!count) return minutes;
        return -1;
    }
};