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
        vector<int> v;
        queue<TreeNode*> q;
        if(root!=NULL){
        q.push(root);}
        while(!q.empty()){
            int tp=q.size();
             
            while(tp>0){
                TreeNode* tp1=q.front();
                q.pop();
                
                if(tp==1){
                    v.push_back(tp1->val);
                }
                if(tp1->left!=NULL){
                    q.push(tp1->left);
                }
                if(tp1->right!=NULL){
                    q.push(tp1->right);
                }
                tp-=1;
            }
       
        }
        return v;
    }
};