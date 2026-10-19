class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count1 = 0;  // Number of elements less than target
        int count2 = 0;  // Number of elements equal to target
        for (int &num : nums) {
            if(num < target) count1++;
            else if(num == target) count2++;
        }
        vector<int> result;
        for(int i = count1; i < count1+count2; i++) result.push_back(i);
        return result;
    }
};