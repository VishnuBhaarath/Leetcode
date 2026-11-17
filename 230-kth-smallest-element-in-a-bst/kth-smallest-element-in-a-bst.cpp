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
    int val1=-1;
    int cnt=0;
    void traverse(TreeNode* root,int k){
        if(root==NULL){
            return;
        }
        
        traverse(root->left,k);
        cnt+=1;
       
        if(cnt==k){
            val1=root->val;
        }
        traverse(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return val1;
        
    }
};