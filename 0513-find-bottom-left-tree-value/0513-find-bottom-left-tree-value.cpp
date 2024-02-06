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
    int findBottomLeftValue(TreeNode* root){
        vector<int> ans;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int temp;
        while(q.size()){
            int s=q.size();
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                temp = node->val;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return temp;
    }
};