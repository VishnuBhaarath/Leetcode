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
    int ans=INT_MIN;
    int sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
       
        long long int lh=sum(root->left);
        long long int rh=sum(root->right);
       long long int sum1=root->val;
        if(lh>=0 && rh>=0){
            sum1+=(lh+rh);
        }
        else if(lh>=0){
            sum1+=lh;
        }
        else if(rh>=0){
            sum1+=rh;
        }
       
        long long int val=root->val+lh;
        long long int val1=root->val+rh;
        long long int val2=max(val1,val);
      

    
        if(sum1>=ans){
            ans=sum1;
        }
        return max(val2, (long long)root->val);


    }
    int maxPathSum(TreeNode* root) {
        if(root!=NULL){
            ans=max(ans,root->val);
        }
        sum(root);
        return ans;
    }
};