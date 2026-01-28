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
        queue<TreeNode*> q;
        
        q.push(root);
        vector<int> v;
        if(root==NULL){
            return v;
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz>0){
               if(sz==1){
                v.push_back(q.front()->val);
               }
               TreeNode* tp=q.front();
               q.pop();
               if(tp->left!=NULL){
                q.push(tp->left);
               }
               if(tp->right!=NULL){
                q.push(tp->right);
               }
               sz-=1;
               
            }
        }
        return v;
    }
};