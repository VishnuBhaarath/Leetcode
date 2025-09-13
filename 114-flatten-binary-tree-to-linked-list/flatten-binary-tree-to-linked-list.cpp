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
    vector<TreeNode*> v;
    void traversal(TreeNode* root){
         if(root==NULL){
            return;
         }
       
         v.push_back(root);
         traversal(root->left);
         traversal(root->right);
    }
    void flatten(TreeNode* root) {
        traversal(root);
        for(int i=1;i<v.size();i++){
          root->left=NULL;
          root->right=v[i];
          root=root->right;
         
        }
    }
};