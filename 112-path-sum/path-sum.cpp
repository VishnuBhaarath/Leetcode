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
   bool traversal(TreeNode* root, int sum,int targetSum){
     if(root->left==NULL && root->right==NULL){
        if(sum==targetSum){
            return true;
        }
        else{
            return false;
        }
     }
    if(root->left!=NULL && root->right!=NULL){
    return (traversal(root->left,sum+root->left->val,targetSum) || traversal(root->right,sum+root->right->val,targetSum));}
    else if(root->left!=NULL){
        return traversal(root->left,sum+root->left->val,targetSum);
    }
    else if(root->right!=NULL){
        return traversal(root->right,sum+root->right->val,targetSum);
    }
    return true;
   }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            
            return false;
        }
        return traversal(root,root->val,targetSum);
        
    }
};