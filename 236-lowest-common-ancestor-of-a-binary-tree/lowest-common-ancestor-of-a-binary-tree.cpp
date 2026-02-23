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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
   
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode* lh=lowestCommonAncestor(root->left,p,q);
      
        TreeNode* rh=lowestCommonAncestor(root->right,p,q);
        
        if(lh!=NULL && rh!=NULL){
            return root;
        }
        else if(lh!=NULL){
            return lh;
        }
        return rh;
    }
    
};