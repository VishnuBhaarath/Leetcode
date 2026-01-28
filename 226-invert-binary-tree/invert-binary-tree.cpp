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
    TreeNode* head;
    void traversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        TreeNode* temp=root->right;
        root->right=root->left;
        root->left=temp;
        traversal(root->left);
        traversal(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
         head=root;
         traversal(root);
         return head;
    }
};