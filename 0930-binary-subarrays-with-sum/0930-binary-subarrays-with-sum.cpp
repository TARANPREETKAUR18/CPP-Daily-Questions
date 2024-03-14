class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> freq(goal+n+1, 0);
        int sum=0, cnt=0;
        for(int x:nums){
            sum+=x;
            if(sum==goal) cnt++;
            if (freq[sum]!=0) 
                cnt+=freq[sum];
            freq[sum+goal]++;
        }
        return cnt;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();