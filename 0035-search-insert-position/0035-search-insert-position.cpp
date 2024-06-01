class Solution {
public:
    
    bool isGreaterOrEqual(int num, int target) {
        return num >= target;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        
        int lo = -1, hi = nums.size(), mid;
        
        while(lo + 1 < hi){
            
            mid = lo + floor((hi - lo) / 2);
            
            if(isGreaterOrEqual(nums[mid], target)){      
                hi = mid;    
            }
            
            else{
                lo = mid;        
            }
          
       }
       
//        if (hi == nums.size() || nums[hi] != target) {
//             return ;
//        }
        
       return hi;
    }
};