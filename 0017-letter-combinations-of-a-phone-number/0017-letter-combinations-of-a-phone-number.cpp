class Solution {
public:
    void generateComb(int i, string& digits, string& temp, vector<string>& ans, vector<string>& mapping){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }
        int index = digits[i] - '0';
        for(int j=0; j<mapping[index].size(); j++){
            temp.push_back(mapping[index][j]);
            generateComb(i+1,digits,temp,ans,mapping);
            temp.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> ans;
        string temp;
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        generateComb(0,digits,temp,ans,mapping);
        return ans;
    }
};