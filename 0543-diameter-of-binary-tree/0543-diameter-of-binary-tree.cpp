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
class Solution{
public:
    int diameter(TreeNode* root, int& h){
        int lh = 0, rh = 0;
        if(!root) return 0;
        int ld = diameter(root->left, lh);
        int rd = diameter(root->right, rh);
        h = 1 + max(lh, rh);
        return max(max(ld, rd), (lh + rh));
    }
    int diameterOfBinaryTree(TreeNode* root){
        int h = 0;
        return diameter(root, h);
    }
};