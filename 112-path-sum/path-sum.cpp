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
    bool ans=false;
    void traversal(TreeNode* root,int sum,int targetSum){
        if(ans){
            return;
        }

        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
             
               if(root->val+sum==targetSum){
                ans=true;
               }
              
               return;
        }
        traversal(root->left,root->val+sum,targetSum);
        traversal(root->right,root->val+sum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        traversal(root,0,targetSum);
        return ans;
    }
};