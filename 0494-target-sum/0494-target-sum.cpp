class Solution {
public:
    int recc(vector<int>& nums, int t, int i, map<pair<int, int>, int> &dp) {
        if(i==nums.size()) return t==0;
        if(dp.count({t, i})) return dp[{t, i}];
        return dp[{t, i}] = recc(nums, t-nums[i], i+1, dp) + recc(nums, t+nums[i], i+1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return recc(nums, target, 0, dp);
    }
};

// [1, 2, 1] - target=2
// [1, 2, 1]
// [1, 2, 1]
