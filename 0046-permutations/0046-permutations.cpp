class Solution {
    vector<vector<int>> answer;
    vector<int> ans;
    vector<bool> isVisited;
    void solve(vector<int>& nums, int& n){
        if(ans.size()==n){
            answer.push_back(ans);
            return;
        }
        for(int i=0; i<n; i++){
            if(isVisited[i])
                continue;
            ans.push_back(nums[i]);
            isVisited[i]=true;
            solve(nums, n);
            ans.pop_back();
            isVisited[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        answer = {};
        ans={};
        int n=nums.size();
        isVisited=vector<bool>(n, false);
        solve(nums, n);
        return answer;        
    }
};
//original solution: https://leetcode.com/problems/permutations/solutions/1257633/backtracking-solution-c-easy-to-understa-cey0/comments/1298625/