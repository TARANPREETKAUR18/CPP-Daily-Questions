class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();

        long long result = 0;

        int curr = 0;
        int prev = 0;
        // TC->O(N)
        // SC->O(1)
        for(int i = 0; i < n; i++){
            curr = target[i] - nums[i];

            //sign change
            if((curr > 0 && prev < 0) || (curr < 0 && prev > 0)){
                result += abs(curr); 
            }
          // both for no sign change
            //collective increment/decrement for a subarray
            else if(abs(curr) > abs(prev)){
                result +=abs(curr - prev);
            }
            //separate increment/decrement
            else if(abs(curr) <= abs(prev)){
                //do nothing
            }

            prev = curr;
        }

        return result;
    }
};