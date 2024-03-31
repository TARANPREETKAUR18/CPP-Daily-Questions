class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int arraySize = nums.size();
        int shortestLength = arraySize + 1;
        for (int start = 0; start < arraySize; ++start) {
            int currentOR = 0;
            for (int end = start; end < arraySize; ++end) {
                currentOR |= nums[end];
                if (currentOR >= k) {
                    shortestLength = min(shortestLength, end - start + 1);
                    break;
                }
            }
        }
        return shortestLength == arraySize + 1 ? -1 : shortestLength;
    }
};