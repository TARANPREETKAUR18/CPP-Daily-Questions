class Solution {
public:
    int dist(char a, char b) {
        int temp = abs(a - b);
        return min(temp, 26 - temp);
    }

    string getSmallestString(string s, int k) {
        for (char &c : s) {
            int diff = dist(c, 'a');
            if (diff <= k) c = 'a', k -= diff;
            else
                for (char i = 'a'; i <= 'z'; i++) {
                    if (dist(c, i) <= k) {
                        k -= dist(c, i);
                        c = i;
                        break;
                    }
            }
        }
        return s;
    }
};