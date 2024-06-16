class Solution {
public:
    int recc(vector<int>& nums, int t, int i) {
        if(i==nums.size()) return t==0;
        return recc(nums, t-nums[i], i+1) + recc(nums, t+nums[i], i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recc(nums, target, 0);
    }
};

// [1, 2, 1] - target=2
// [1, 2, 1]
// [1, 2, 1]
