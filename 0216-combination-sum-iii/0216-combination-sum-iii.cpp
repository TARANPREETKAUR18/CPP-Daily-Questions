class Solution{
public:
    void combine(int index, int k, int sum, vector<vector<int>> &ans, vector<int> &temp){
        if(k==0){
            if(sum==0) ans.push_back(temp);
            return;
        }
        for(int i=index; i<10; i++){
            if((i>index && i==index) || index>sum) return;
            temp.push_back(i);
            combine(i+1, k-1, sum-i, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> ans;
        vector<int> temp;
        combine(1, k, n, ans, temp);
        return ans;
    }
};