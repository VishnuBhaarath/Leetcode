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
    int traversal(TreeNode* root){
         if(root==NULL){
            return 0;
         }
        
        int lh=traversal(root->left);
        int rh=traversal(root->right);

        int val=max(lh,rh);
        int sum=0;
        if(lh>0 && rh>0){
            sum=lh+rh;
        }
        else if(lh>0){
            sum=lh;
        }
        else if(rh>0){
            sum=rh;
        }
        ans=max(ans,sum+root->val);
        if(val<0){
            val=root->val;
        }
        else{
        val+=root->val;}
        return val;

         
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        cout<<traversal(root);
       
       // ans=max(ans,root->val);
       
        
       

     
        return ans;
    }
};