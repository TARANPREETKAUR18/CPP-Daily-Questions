class Solution {
public:
    long long cnt = 0;
    long long prefix = 0;
    unordered_map<long long,long long> mp;
    
    void dfs(TreeNode* root, long long target) {
        if(root == nullptr) return;
        prefix += root->val;
        // Number of valid paths ending here.
        cnt += mp[prefix - target];
        // Add current prefix.
        mp[prefix]++;
        dfs(root->left, target);
        dfs(root->right, target);
        // Remove current prefix before
        // exploring another branch.
        mp[prefix]--;
        // Restore previous prefix sum.
        prefix -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        // Empty prefix before DFS starts.
        mp[0] = 1;
        dfs(root, targetSum);
        return cnt;
    }
};