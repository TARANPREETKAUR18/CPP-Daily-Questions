/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, long long targetSum) {
        if(!root) return 0;
        int ans=0;
        if(targetSum == root->val) ans+=1;
        ans+=solve(root->left, targetSum-root->val) + solve(root->right, targetSum-root->val);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + solve(root, targetSum);
    }
};