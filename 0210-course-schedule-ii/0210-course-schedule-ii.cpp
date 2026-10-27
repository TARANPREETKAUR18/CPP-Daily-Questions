class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, unordered_set<int>& s, vector<bool>& vis, stack<int> &st){
        s.insert(i);
        vis[i] = true;
        for(int neighbour : adj[i]) {
            if(!vis[neighbour] && !dfs(neighbour, adj, s, vis, st)) return false;
            else if(s.count(neighbour)) return false;
        }
        s.erase(i);
        st.push(i);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(numCourses, false);
        stack<int> st;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                unordered_set<int> s;
                if(!dfs(i, adj, s, vis, st)) return {};
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};