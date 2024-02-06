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
    void isTargetSum(TreeNode* head, int targetSum, int tempSum, vector<int> temp, vector<vector<int>> &ans){
        tempSum+=head->val;
        temp.push_back(head->val);
        if(!head->left && !head->right && targetSum == tempSum){
            ans.push_back(temp);
            return;
        }
        if(head->left) isTargetSum(head->left, targetSum, tempSum, temp, ans);
        if(head->right) isTargetSum(head->right, targetSum, tempSum, temp, ans);
        tempSum-=head->val;
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        isTargetSum(root, targetSum, 0, {}, ans);
        return ans;
    }
};