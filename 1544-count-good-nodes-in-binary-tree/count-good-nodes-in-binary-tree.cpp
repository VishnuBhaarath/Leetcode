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
    int cnt=0;
    void traversal(TreeNode* root,int val){
        if(root==NULL){
            return;
        }
        if(root->val>=val){
            cnt+=1;
        }
        if(root->left!=NULL){
            int val1=max(val,root->left->val);
        traversal(root->left,val1);}

        if(root->right!=NULL){
            int val1=max(val,root->right->val);
        traversal(root->right,val1);}
    }
    int goodNodes(TreeNode* root) {
       
        traversal(root,root->val);
        return cnt;
    }
};