class Solution {
public:
    
    bool canColor(vector<vector<int>> &graph, int node, bool prevColor, vector<int> &colored) {
        cout<<node<<" ";
        colored[node]=!prevColor;
        for (int i = 0; i<graph[node].size(); i++) {
            if(colored[node]==colored[graph[node][i]]) return false;
            if(colored[graph[node][i]]==-1)
                if(!canColor(graph, graph[node][i], colored[node], colored)) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(), -1);
        for (int i=0; i<graph.size(); i++)
            if(colored[i]==-1 && !canColor(graph, i, 0, colored)) return false;
        return true;
    }
};