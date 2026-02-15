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
     int ans=0;
    int height(TreeNode* root){
         if(root==NULL){
            return 0;
         }
         int lh=1+height(root->left);
         int rh=1+height(root->right);
      
         if(abs(lh-rh)>1){
            ans=-1;
         }
          
         return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        if(ans==-1){
            return false;
        }
        return true;
    }
};