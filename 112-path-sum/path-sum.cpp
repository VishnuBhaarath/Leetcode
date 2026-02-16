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
    int t=0;
    void traversal(TreeNode* root, int sum,int val){
        if(t==1){
            return;
        }
        if(root==NULL){
            return;
        }
      
        if(val==sum && root->left==NULL && root->right==NULL){
            t=1;
            return;
        }
        if(root->left!=NULL)
        traversal(root->left,sum,val+root->left->val);

        if(root->right!=NULL)
        traversal(root->right,sum,val+root->right->val);
    }
  
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
         traversal(root,targetSum,root->val);
         if(t==0){
            return false;
         }
         return true;
    }
};