class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums, int target, int i, int j) {
        while (i < j) {
            if (nums[i] + nums[j] > target)
                j--;
            else if (nums[i] + nums[j] < target)
                i++;
            else {
                // first we will remove duplicates from wither end(i,j)
                while (i < j && nums[i] == nums[i + 1])
                    i++;
                while (i < j && nums[j] == nums[j - 1])
                    j--;
                result.push_back({-target, nums[i], nums[j]});
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};

        result.clear();

        // sort
        sort(begin(nums), end(nums));

        // fixing one element : n1
        for (int i = 0; i <= n - 3; i++) { // we need at least 3 elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int n1 = nums[i];
            int target = -n1;

            // it will find n1 & n3: {n1, n2, n3}
            twoSum(nums, target, i + 1, n - 1);
        }
        return result;
    }
};