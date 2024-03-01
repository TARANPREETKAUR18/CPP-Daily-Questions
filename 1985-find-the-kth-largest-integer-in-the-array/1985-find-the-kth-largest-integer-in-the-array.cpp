class Solution {
public:
    static bool comperator(string &a, string &b) {
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comperator);
        return nums[nums.size()-k];
    }
};