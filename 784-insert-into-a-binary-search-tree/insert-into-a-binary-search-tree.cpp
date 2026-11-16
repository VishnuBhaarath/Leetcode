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
    void traverse(TreeNode* root, int val){
        if(val>root->val){
            if(root->right==NULL){
                TreeNode* temp=new TreeNode();
                temp->val=val;
                temp->left=NULL;
                temp->right=NULL;
                root->right=temp;
                return;
            }
            traverse(root->right,val);
        }
        else{
            if(root->left==NULL){
                TreeNode* temp=new TreeNode();
                temp->val=val;
                temp->left=NULL;
                temp->right=NULL;
                root->left=temp;
                return;
            }
            traverse(root->left,val);
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode* temp=root;
        if(root==NULL){
            TreeNode* temp=new TreeNode();
                temp->val=val;
                temp->left=NULL;
                temp->right=NULL;
                //root->left=temp;
                return temp;

        }
        traverse(root,val);
        return temp;
    }
};