class Solution {
public:
    bool recc(vector<int>& nums, int s1, int s2, int i, vector<vector<int>> &dp) {
        if(i==nums.size() && s1!=s2) return false;
        if(i==nums.size() && s1==s2) return true;
        if(dp[i][s1]!=-1) return dp[i][s1];
        return dp[i][s1]=recc(nums, s1+nums[i], s2, i+1, dp) || recc(nums, s1, s2, i+1, dp); 
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(sum, -1));
        if(sum%2) return false;
        return recc(nums, 0, sum/2, 0, dp);
    }
};