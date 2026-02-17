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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* temp1=root;
        if(root==NULL){
            temp1=new TreeNode();
            temp1->val=val;
            temp1->left=NULL;
            temp1->right=NULL;
        }
        while(root!=NULL){
             if(root->val<val){
                if(root->right==NULL){
                    TreeNode* temp=new TreeNode();
                    temp->val=val;
                    temp->left=NULL;
                    temp->right=NULL;
                    root->right=temp;
                    return temp1;
                }
                root=root->right;
             }
             else if(root->val>val){
                if(root->left==NULL){
                    TreeNode* temp=new TreeNode();
                    temp->val=val;
                    temp->left=NULL;
                    temp->right=NULL;
                    root->left=temp;
                    return temp1;
                }
                 root=root->left;
             }
        }
        return temp1;
    }
};