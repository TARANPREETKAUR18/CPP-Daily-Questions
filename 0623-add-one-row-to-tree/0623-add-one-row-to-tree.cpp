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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* ro = new TreeNode(val);
            ro->left = root;
            return ro;
        }
        queue<TreeNode*>q;
        q.push(root);
        int dep = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(dep==depth-2){
                    TreeNode* temp1 = temp->left;
                    TreeNode* temp2 = temp->right;
                    temp->left = new TreeNode(val);
                    temp->right = new TreeNode(val);
                    temp->left->left = temp1;
                    temp->right->right = temp2;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            dep++;
        }
        cout<<dep;
        return root;
    }
};