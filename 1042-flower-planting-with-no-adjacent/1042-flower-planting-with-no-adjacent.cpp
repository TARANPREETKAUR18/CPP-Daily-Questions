class Solution {
public:
    void bfs(int node, vector<int> &partition, vector<vector<int>> &adj){
        queue<pair<int, int>> q;
        q.push({node, 1});
        partition[node] = 1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int val = it.second;
            for(auto nxtNode : adj[node]){
                if(partition[nxtNode] == -1){
                    int newVal = (val % 4) + 1;
                    partition[nxtNode] = newVal;
                    q.push({nxtNode, newVal});
                }
                else if(partition[node] == partition[nxtNode]) partition[nxtNode] = (partition[nxtNode] % 4) + 1;
            }
        }
        return;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto it : paths){
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<int> partition(n, -1);
        for(int i = 0; i < n; i++)
            if(partition[i] == -1) bfs(i, partition, adj);
        return partition;
    }
};