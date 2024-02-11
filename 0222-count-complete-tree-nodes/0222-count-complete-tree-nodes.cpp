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
    int countNodes(TreeNode* root){
        if(root==NULL) return 0;
        int cnt = 0;
        queue<TreeNode*> q;
        TreeNode* temp = root;
        q.push(temp);
        while(!q.empty()){
            temp = q.front();
            cnt++;
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return cnt;
    }
};