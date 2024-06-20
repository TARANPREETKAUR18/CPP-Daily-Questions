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
    int solve(TreeNode* root, int prev) {
        if(!root) return 0;
        int ans=1;
        if(root->val!=prev) return 0;
        ans+= max(solve(root->left, prev), solve(root->right, prev));
        return ans;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        return max(max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)), solve(root->left, root->val) + solve(root->right, root->val));
    }
};