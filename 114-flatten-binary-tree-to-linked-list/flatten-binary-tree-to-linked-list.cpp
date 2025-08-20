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
    void flatten(TreeNode* root) {
        TreeNode * prev= NULL;
        while(root!=NULL){
            if(root->left==NULL){
               
                root=root->right;
            }
            else{
                TreeNode* curr=root;
                curr=curr->left;
                while(curr->right!=NULL && curr->right!=root->right){
                    curr=curr->right;
                }
                if(curr->right==NULL){
                    curr->right=root->right;
                   
                    TreeNode* temp=root->left;
                    root->left=NULL;
                    root->right=temp;
                    root=root->right;
                }
                else{
                    curr->right=NULL;
                    root=root->right;
                }
            }
        }
        
    }
};