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
    bool checkBST(TreeNode* root,long long val1,long long val2){
        if(root==NULL){
            return true;
        }
        if(root->val<=val1 || root->val>=val2){
            return false;
        }
        long long l=val2;
        long long r=val1;
        if(root->val<l){
            l=root->val;
        }
        if(root->val>r){
            r=root->val;
        }

       return checkBST(root->left,val1,l) && checkBST(root->right,r,val2);
    }
    bool isValidBST(TreeNode* root) {
       
         return checkBST(root,-2147483649,2147483649);
    }
};