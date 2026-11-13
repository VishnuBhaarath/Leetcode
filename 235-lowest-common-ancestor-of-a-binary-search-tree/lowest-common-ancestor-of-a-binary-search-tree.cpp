/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans=NULL;
    void check(TreeNode* root, TreeNode* p, TreeNode* q){
         if(root==NULL){
            return;
         }
         if(ans!=NULL){
            return;
         }
        
         if(root->val==p->val || root->val==q->val){
            ans=root;
           
            return;
         }
         else if((root->val<p->val && root->val>q->val) || (root->val>p->val && root->val<q->val)){
         
            ans=root;
            return;
         }
         else{
             if(root->val<p->val && root->val<q->val){
                root=root->right;
             }
             else if(root->val>p->val && root->val>q->val){
                 cout<<"in3";
                root=root->left;
             }
             check(root,p,q);
         }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root,p,q);
        return ans;
    }
};