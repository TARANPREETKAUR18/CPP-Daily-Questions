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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(root->val);
        while (!q.empty()) {
            int size = q.size();
            bool flag=false;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->right) {
                    if(flag == false) ans.push_back(node->right->val);
                    q.push(node->right);
                    flag=true;
                }
                if (node->left) {
                    if(flag == false) ans.push_back(node->left->val);
                    q.push(node->left);
                    flag=true;
                }
            }
        }
        return ans;
    }
};