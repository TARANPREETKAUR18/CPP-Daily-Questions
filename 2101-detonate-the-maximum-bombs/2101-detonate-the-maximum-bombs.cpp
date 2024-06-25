class Solution {
public:
    double distance(int x1, int x2, int y1, int y2) {
        return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
    }
    
    int bombsDetonated(vector<vector<int>> &isConnected, int index, vector<bool> &visited) {
        int detonated = 1;
        visited[index] = true;
        for(int i= 0; i<isConnected[index].size(); i++) {
            if(!visited[isConnected[index][i]]) {
                detonated+=bombsDetonated(isConnected, isConnected[index][i], visited);
            }
        }
        return detonated;
    }
    
    int maximumDetonation(vector<vector<int>>& bomb) {
        vector<vector<int>> isConnected(bomb.size(), vector<int>(0));
        for(int i=0; i<bomb.size(); i++) {
            for(int j=0; j<bomb.size(); j++) {
                if(i!=j && distance(bomb[i][0], bomb[j][0], bomb[i][1], bomb[j][1])<=bomb[i][2]) {
                    isConnected[i].push_back(j);
                }
            }
        }
        int maxDetonated=1;
        for(int i=0; i<bomb.size(); i++) {
            vector<bool> visited(bomb.size(), false);
            int currDetonated = bombsDetonated(isConnected, i, visited);
            maxDetonated = max(maxDetonated, currDetonated);
        }
        return maxDetonated;
    }
};
