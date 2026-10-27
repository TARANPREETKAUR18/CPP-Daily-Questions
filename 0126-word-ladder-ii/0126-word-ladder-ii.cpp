class Solution {
    vector<vector<string>> answer;
    unordered_map<string, int> distance;
    string begin;
    int length;

    void dfs(const string& word, vector<string>& path) {
        if (word == begin) {
            answer.emplace_back(path.rbegin(), path.rend());
            return;
        }
        string candidate = word;
        for (int i = 0; i < length; ++i) {
            char old = candidate[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                candidate[i] = ch;
                auto it = distance.find(candidate);
                if (it != distance.end() && it->second + 1 == distance[word]) {
                    path.push_back(candidate);
                    dfs(candidate, path);
                    path.pop_back();
                }
            }
            candidate[i] = old;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        begin = beginWord;
        length = begin.size();
        unordered_set<string> remaining(wordList.begin(), wordList.end());
        remaining.erase(begin);
        queue<string> queue;
        queue.push(begin);
        distance[begin] = 1;
        while (!queue.empty()) {
            string word = queue.front();
            queue.pop();
            if (word == endWord) break;
            for (int i = 0; i < length; ++i) {
                string candidate = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    candidate[i] = ch;
                    if (remaining.erase(candidate)) {
                        distance[candidate] = distance[word] + 1;
                        queue.push(candidate);
                    }
                }
            }
        }
        if (distance.count(endWord)) {
            vector<string> path{endWord};
            dfs(endWord, path);
        }
        return answer;
    }
};
