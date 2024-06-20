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
    int height(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(root->left && !root->right) return height(root->left)+1;
        if(!root->left && root->right) return height(root->right)+1;
        return max(height(root->left), height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(isBalanced(root->left) && isBalanced(root->right)) return abs(height(root->left)-height(root->right))<2;
        return false;
    }
};
//             1
//         2       2
//     3               3
// 4                       4