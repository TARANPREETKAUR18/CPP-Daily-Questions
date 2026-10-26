class DisjointSet {
  vector<int> parent, size;

public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
  }

  int findUltimateParent(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findUltimateParent(parent[node]);
  }

  void unionbysize(int u, int v) {
    int ultimateParentOfU = findUltimateParent(u), ultimateParentOfV = findUltimateParent(v);

    if (ultimateParentOfU == ultimateParentOfV) return;

    if (size[ultimateParentOfU] < size[ultimateParentOfV]) {
      parent[ultimateParentOfU] = ultimateParentOfV;
      size[ultimateParentOfV] += size[ultimateParentOfU];
    } else {
      parent[ultimateParentOfV] = ultimateParentOfU;
      size[ultimateParentOfU] += size[ultimateParentOfV];
    }
  }
};

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
    int n = details.size();
    DisjointSet ds(n);
    unordered_map<string, int> mapMailNode;

    for (int i = 0; i < details.size(); i++) {
      for (int j = 1; j < details[i].size(); j++) {
        string mail = details[i][j];
        if (mapMailNode.find(mail) == mapMailNode.end()) {
          mapMailNode[mail] = i;
        } else {
          ds.unionbysize(mapMailNode[mail], i);  // ds.unionbysize(i ,  mapMailNode[mail]) this wont work 
        }
      }
    }

    vector<string> mergedMail[n];
    for (auto it : mapMailNode) {
      string mail = it.first;
      int node = ds.findUltimateParent(it.second);
      mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++) {
      if (mergedMail[i].size() == 0) continue;
      sort(mergedMail[i].begin(), mergedMail[i].end());
      vector<string> temp;
      temp.push_back(details[i][0]);
      for (auto it : mergedMail[i]) temp.push_back(it);
      ans.push_back(temp);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};