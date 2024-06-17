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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if both trees' root node == NULL, then return trees are same;
        if(p == NULL && q == NULL) return true;
        
        //if either of the corresponding node is NULL || value of corresponding node is different then trees are not same
        if(((p == NULL) && q) || (p && (q == NULL)) || (q->val!=p->val)) return false;
        
        //checking if both the sub-trees are same or not
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};