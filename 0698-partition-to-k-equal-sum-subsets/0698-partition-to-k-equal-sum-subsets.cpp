class Solution {
public:
    bool recc(vector<int> &nums, int target, int i, int k, int sum, int visited, vector<vector<int>> &dp) {
        if(k==0) return true;
        if(target==0) return dp[k][visited] = recc(nums, sum, 0, k-1, sum, visited, dp);
        if(i>=nums.size()) return false;
        bool pick=false;
        if(dp[k][visited]!=-1) return dp[k][visited];
        if(target<=sum && !(visited &(1<<i))){
            pick = recc(nums, target-nums[i], i+1, k, sum, visited|(1<<i), dp);
        }
        return dp[k][visited] = pick || recc(nums, target, i+1, k, sum, visited, dp);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return false;
        int visited=0;
        vector<vector<int>> dp(k+1, vector<int>(1<<nums.size(), -1));
        return recc(nums, sum/k, 0, k, sum/k, visited, dp);
    }
};

// [1, 3, 2, 1, 1, 1] - 1+2, 3, 1+1+1
// [4, 3, 2, 3, 5, 2, 1], k=4
// sum = 20, target = 5
// [4, 1], [2, 3], [3, 2], [5] - true