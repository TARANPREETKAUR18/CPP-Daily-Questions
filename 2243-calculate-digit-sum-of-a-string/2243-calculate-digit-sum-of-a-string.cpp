class Solution {
public:
    string digitSum(string s, int k) {
        vector<int> cur;
        for (char c : s) cur.push_back(c - '0');
        while (cur.size() > k) {
            vector<int> nxt;
            for (int i = 0; i < cur.size(); i += k) {
                int sum = 0;
                for (int j = i; j < cur.size() && j < i + k; j++) sum += cur[j];
                int start = nxt.size();
                if (sum == 0) nxt.push_back(0);
                while (sum > 0) {
                    nxt.push_back(sum % 10);
                    sum /= 10;
                }
                reverse(nxt.begin() + start, nxt.end());
            }
            cur = nxt;
        }
        string res;
        for (int d : cur) res += char('0' + d);
        return res;
    }
};