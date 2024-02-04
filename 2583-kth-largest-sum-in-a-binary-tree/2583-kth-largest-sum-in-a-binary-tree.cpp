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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> output;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int s=q.size();
            long long sum = 0;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            output.push_back(sum);
        }
        if(k>output.size()) return -1;
        sort(output.rbegin(), output.rend());
        return output[k-1];
    }
};