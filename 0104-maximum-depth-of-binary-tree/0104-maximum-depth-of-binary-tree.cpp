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
    int totalDepth(TreeNode* root, int depth) {
        if(!root->left && !root->right) return depth;
        int maxLeftDepth = 0, maxRightDepth = 0;
        if(root->left)  maxLeftDepth = totalDepth(root->left, depth+1);
        if(root->right) maxRightDepth = totalDepth(root->right, depth+1);
        return max(maxLeftDepth, maxRightDepth);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return totalDepth(root, 1);
    }
};