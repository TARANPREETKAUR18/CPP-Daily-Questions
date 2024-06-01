class Solution {
public:
    bool isMinimal(int mid, int target) {
        return mid >= target;
    }
    
    int firstOccurance(vector<int> &nums, int target){
        int lo = -1, hi = nums.size(), mid;
        while(lo + 1 < hi){
            mid = lo + floor((hi - lo) / 2);
            if(isMinimal(nums[mid], target)) hi = mid;
            else lo = mid;
        }
        if(hi == nums.size() || nums[hi] != target) return -1;
        return hi;
    }
    
    bool isMaximal(int mid, int target) {
        return mid <= target;
    }
    
    int lastOccurance(vector<int> &nums, int target) {
        int lo = -1, hi = nums.size(), mid;
        while(lo + 1 < hi){
            mid = lo + floor((hi - lo) / 2);
            if(isMaximal(nums[mid], target)) lo = mid;
            else hi = mid;
        }
        if((lo == -1) || nums[lo] != target) return -1;
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurance(nums, target), lastOccurance(nums, target)};
    }
};