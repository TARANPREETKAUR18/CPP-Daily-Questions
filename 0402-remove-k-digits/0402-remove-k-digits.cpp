class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(int i=0;i<num.size();++i){
            while(res.size() != 0 and num[i] < res.back() and k != 0) res.pop_back(),k--;
            res.push_back(num[i]);
        }
        while(k--) res.pop_back();
        int i=0;
        while(i<res.size() and res[i]=='0') i++;
        string ans = res.substr(i);
        return ans.size() ? ans : "0";
    }
};