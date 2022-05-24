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
    bool isValidBST(TreeNode* root) {
        
        long long int min=-100000000001;
        long long int max=100000000001;
        bool ans=validate(root,min,max);
        return ans;
    }
    bool validate(TreeNode* root, long long int l,long long int h){
        if(root==NULL){
            return true;
        }
        if(root->val<=l || root->val>=h){
            return false;
        }
        return validate(root->left,l,root->val) && validate(root->right,root->val,h);
    }
};