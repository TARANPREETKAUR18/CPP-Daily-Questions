class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int &num: nums){
            result += mp[num];
            mp[num]++;
        }

        return result;
    }
};