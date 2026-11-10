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
    int ans1=0;
    int check(TreeNode * root){
         if(root==NULL){
            return 0;
         }
         int lh=check(root->left);
         int rh=check(root->right);
          ans1=max(ans1,lh+rh);
          cout<<ans1;
          cout<<"\n";
         return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return ans1;
    }
};