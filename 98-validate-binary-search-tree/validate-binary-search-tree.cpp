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
    bool check(TreeNode* root,long long int l,long long int r){
        if(root==NULL){
            return true;
        }
        

        if(root->val<=l || root->val>=r){
            return false;
        }
        long long int val1=r;
        if(root->val<val1){
            val1=root->val;
        }
        long long int val2=l;
        if(root->val>val2){
            val2=root->val;
        }
        return check(root->left,l,root->val) && check(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
      return check(root,-2147483649,2147483649);
        
    }
};