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
    vector<int> largestValues(TreeNode* root) {
        vector<int> output;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int s=q.size();
            int res = INT_MIN;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                res=max(node->val, res);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            output.push_back(res);
        }
        return output;
    }
};