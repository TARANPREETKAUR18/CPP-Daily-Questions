class Solution {
public:
    int recc(vector<int> &nums, int i, vector<int> &dp) {
        if(nums[i]+i+1>=nums.size()) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=1; j<nums[i]+1; j++) if(recc(nums, i+j, dp)) return dp[i]=true;
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recc(nums, 0, dp);
    }
};