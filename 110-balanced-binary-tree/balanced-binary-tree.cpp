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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }   
        cout<<"r";
        cout<<root->val;
        cout<<" ";
        if(t==-1){
            return 0;
        }
        int lh=1+height(root->left);
        int rh=1+height(root->right);
        cout<<lh;
        cout<<" ";
        cout<<rh;
        if(abs(lh-rh)>1){
            t=-1;
        }
        cout<<"\n";
        return max(lh,rh);

    }
    bool isBalanced(TreeNode* root) {
       
         height(root);
           if(t==-1){
            return false;
         }
         return true;
    }
};