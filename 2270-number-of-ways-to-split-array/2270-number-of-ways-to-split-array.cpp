class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        long long lsum = 0LL, rsum;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = 0; i < n-1; i++){
            lsum += nums[i];
            rsum = sum-lsum;
            if(lsum >= rsum) cnt++;
        }
		return cnt;
    }
};