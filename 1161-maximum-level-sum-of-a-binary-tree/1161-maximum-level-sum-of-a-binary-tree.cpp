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
    int maxLevelSum(TreeNode* root) {
        vector<double> output;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        int cnt = 1;
        int max_sum = root->val;
        while(q.size()){
            int s=q.size();
            int sum = 0;
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum>max_sum){
                max_sum=sum;
                ans=cnt;
            }
            cnt++;
        }
        return ans;
    }
};