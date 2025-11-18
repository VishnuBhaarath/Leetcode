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
   bool val=true;
    int func(TreeNode* root){
         if(root==NULL){
            return 0;
         }
         int lh=1+func(root->left);
         int rh=1+func(root->right);
      
         if((abs(lh-rh))>1){
            val=false;
         }
       
         return max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        func(root);
        return val;
    }
};