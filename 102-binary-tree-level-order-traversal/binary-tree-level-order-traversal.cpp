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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        if(root!=NULL)
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
             int sz=q.size();
             vector<int> v;
             while(sz>0){
                TreeNode* tp=q.front();
                q.pop();
                v.push_back(tp->val);
                if(tp->left!=NULL){
                    q.push(tp->left);
                }
                if(tp->right!=NULL){
                    q.push(tp->right);
                }
                sz-=1;
             }
             ans.push_back(v);
        }
        return ans;
    }
};