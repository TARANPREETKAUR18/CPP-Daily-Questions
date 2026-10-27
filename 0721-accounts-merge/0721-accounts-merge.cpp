class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_parent = find(x), y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] > rank[y_parent]) parent[y_parent] = x_parent;
        else if (rank[x_parent] < rank[y_parent]) parent[x_parent] = y_parent;
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string, int> emails;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(emails.find(email) == emails.end()) emails[email] = i;
                else Union(i, emails[email]);
            }
        }
        vector<vector<string>> merged(n);
        for(auto it: emails) {
            int root = find(it.second);
            merged[root].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end(), merged[i].begin(), merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};