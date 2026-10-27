class Solution {
public:
    int bfs(unordered_map<string, vector<string>>& m, string s, unordered_map<string, bool>& vis, string tar) {
        queue<pair<string, int>> q;
        q.push({s, 1});
        vis[s] = true;
        while (q.size() > 0) {
            pair<string, int> u = q.front();
            q.pop();
            for (auto i : m[u.first]) {
                if (!vis[i]) {
                    if (i == tar) return u.second + 1;
                    q.push({i, u.second + 1});
                    vis[i] = true;
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool chk = false;
        for (auto s : wordList) {
            if (s == endWord) {
                chk = true;
                break;
            }
        }
        if (!chk) return 0;
        unordered_map<string, vector<string>> m;
        unordered_map<string, bool> vis;
        for (auto i : wordList) {
            m[i] = {};
            vis[i] = false;
            for (auto j : wordList) {
                int changes = 0;
                for (int k = 0; k < beginWord.length(); k++) {
                    if (j[k] != i[k]) changes++;
                }
                if (changes == 1) m[i].push_back(j);
            }
        }
        if (m.find(beginWord) == m.end()) m[beginWord] = {};
        vis[beginWord] = false;
        for (auto i : wordList) {
            int changes = 0;
            for (int k = 0; k < beginWord.length(); k++) {
                if (beginWord[k] != i[k]) changes++;
            }
            if (changes == 1) m[beginWord].push_back(i);
        }
        int ans = bfs(m, beginWord, vis, endWord);
        if (ans == INT_MAX) return 0;
        return ans;
    }
};