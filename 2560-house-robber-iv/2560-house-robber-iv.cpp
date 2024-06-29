class Solution {
public:
    
    bool check(vector<int> nums, int k, int mid) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                i++, count++;
            }
        }
        if(count>=k) return true;
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end()) - 1, hi = *max_element(nums.begin(), nums.end()), mid;
        while (lo + 1 < hi) {
            mid = lo + floor((hi - lo) / 2);
            if (check(nums, k, mid)) {
                hi = mid;
            }
            else {
                lo = mid;
            }
        }
        return hi;
    }
};

// minimization problem

