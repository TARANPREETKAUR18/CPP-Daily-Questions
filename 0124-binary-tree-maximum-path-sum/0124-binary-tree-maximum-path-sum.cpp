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
    int maxPath(TreeNode* head, int &ans){
        if(!head) return 0;
        int sideL = maxPath(head->left, ans);
        int sideR = maxPath(head->right, ans);
        int temp = max(max(sideL, sideR)+head->val, head->val);
        int inter = max(temp, sideL+sideR+head->val);
        ans = max(ans, inter);
        return temp;
    }
    int maxPathSum(TreeNode* root){
        int ans=INT_MIN;
        maxPath(root, ans);
        return ans;
    }
};