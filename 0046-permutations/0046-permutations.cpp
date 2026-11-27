class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int> &nums,int i,int n){
        if(i==n){
            result.push_back(nums);
            return ;
        }
        for(int j=i;j<=n;j++){
            swap( nums[i],nums[j]);
            backtrack(nums,i+1,n);
            swap( nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {      
        backtrack(nums,0,nums.size()-1);
        return result;
    }
};
//original backtracking solution: https://leetcode.com/problems/permutations/solutions/1257633/backtracking-solution-c-easy-to-understa-cey0/comments/1298625/
//swapping solution: https://leetcode.com/problems/permutations/solutions/1257633/backtracking-solution-c-easy-to-understa-cey0