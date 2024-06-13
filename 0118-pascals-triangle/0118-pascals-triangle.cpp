class Solution {
public:
    void recc(int numRows, vector<vector<int>> &ans) {
        if(numRows == 1) {
            ans.push_back({1});
            return;
        }
        recc(numRows-1, ans);
        vector<int> temp(numRows, 1);
        for(int i = 1; i < numRows - 1; i++) {
            temp[i] = ans.back()[i-1] + ans.back()[i];
        }
        
        ans.push_back(temp);
        return;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        recc(numRows, ans);
        return ans;
    }
};