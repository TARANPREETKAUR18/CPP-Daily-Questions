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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans=root->val;
        q.push(root);
        while(q.size()){
            int s=q.size();
            bool flag=false;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->left && !flag) flag=true, ans = node->left->val;
                if(node->right && flag) q.push(node->right);
                if(node->right && !flag){
                    flag = true;
                    ans = node->right->val;
                    q.push(node->right);
                }
            }
            flag=false;
        }
        return ans;
    }
};