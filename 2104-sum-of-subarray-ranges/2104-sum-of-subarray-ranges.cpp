class Solution {
public:
    
//     int solve(vector<int> &nums, int cnt) {
        
//     }
    
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for(int s=0; s<nums.size(); s++) {
            int mini=nums[s], maxi=nums[s];
            for(int e=s; e<nums.size(); e++) {
                mini=min(mini, nums[e]);
                maxi=max(maxi, nums[e]);
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};

// brute force - try all the sub-arrays
// try start & end points