class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = -1, hi = nums.size();
        while(lo + 1 < hi) {
            int mid = lo + floor((hi - lo) / 2);
            long long left = LONG_MIN, right = LONG_MIN;
            if(mid-1 >= 0) left = nums[mid - 1];
            if(mid+1 <= nums.size()-1) right = nums[mid + 1];
            if((left < nums[mid]) && (right < nums[mid])) return mid;
            else if(left > nums[mid]) hi = mid;
            else lo = mid;
        }
        return -1;
    }
};