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
    unordered_map<TreeNode*,int> umap;
    int traversal(TreeNode* root){
         if(root==NULL){
            return 0;
         }
         if(umap[root]!=0){
            return umap[root];
         }
        
        if(root->left!=NULL && root->right!=NULL)
       return umap[root]=max((root->val+traversal(root->left->left)+traversal(root->left->right)+traversal(root->right->left)+traversal(root->right->right)), (traversal(root->left)+traversal(root->right)));
        else if(root->left!=NULL){
              return umap[root]=max((root->val+traversal(root->left->left)+traversal(root->left->right)), (traversal(root->left)+traversal(root->right)));
        }
        else if(root->right!=NULL){
           return umap[root]=max((root->val+traversal(root->right->left)+traversal(root->right->right)), (traversal(root->left)+traversal(root->right)));

        }
        else{
            return umap[root]=max((root->val), (traversal(root->left)+traversal(root->right)));
        }
         return 0;

         
    }
    int rob(TreeNode* root) {
       return traversal(root);

    
    }
};