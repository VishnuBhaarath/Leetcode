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
     return 1+max(height(root->left),height(root->right));
   }
    void traversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        
        ans=max(ans,lh+rh);
        traversal(root->left);
        traversal(root->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        traversal(root);
        return ans;
    }
};