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
    bool isSubTreeSymmetric(TreeNode* leftParent, TreeNode* rightParent) {
        if (!leftParent && !rightParent) return true;
        if ((!leftParent && rightParent) || (leftParent && !rightParent)) return false;
        if ((leftParent->val != rightParent->val)) return false;
        if (!isSubTreeSymmetric(leftParent->left, rightParent->right)) return false;
        if (!isSubTreeSymmetric(leftParent->right, rightParent->left)) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return isSubTreeSymmetric(root->left, root->right);
    }
};

//     1
//  2      2
// 3 4    4 3
//5 9 7  7 9 5
//[left,   [right,
// right,   left,
// root]    root]