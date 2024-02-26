class Solution {
public:
    void dfs(int node, vector<int> adjLs[], int vis[]){
        vis[node]=1;
        for(auto it: adjLs[node]){
            if(!vis[it]) dfs(it, adjLs, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int vis[200]={0};
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};