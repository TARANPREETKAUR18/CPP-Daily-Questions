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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> output;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int s=q.size();
            vector<double> temp;
            long sum = 0;
            int cnt = 0;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                cnt++;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            output.push_back((double)sum/cnt);
        }
        return output;
    }
};