class Solution{
public:
    int dp[101];
    int slv(int i, vector<int> &v){
        if (i >= v.size())return 0;
        int &ret = dp[i];
        if (~ret)return ret;
        ret = max(v[i] + slv(i + 2, v), slv(i + 1, v));
        return ret;
    }

    int rob(vector<int> &nums){
        memset(dp, -1, sizeof dp);
        return slv(0,nums);
    }
};