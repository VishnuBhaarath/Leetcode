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
     map<TreeNode*,int> umap;
    int sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(umap.find(root)!=umap.end()){
            return umap[root];
        }
        return umap[root]= max(0,root->val+ max(sum(root->left),sum(root->right)));
    }
    int maxPathSum(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
       
        while(!st.empty()){
            TreeNode* tp=st.top();
            st.pop();
            if(umap.find(tp->left)==umap.end()){
                umap[tp->left]=sum(tp->left);
            }
            if(umap.find(tp->right)==umap.end()){
                umap[tp->right]=sum(tp->right);
            }
            int val=tp->val+umap[tp->left]+umap[tp->right];
            ans=max(ans,val);
            if(tp->left!=NULL){
                st.push(tp->left);
            }
            if(tp->right!=NULL){
                st.push(tp->right);
            }
        }
        return ans;
        
    }
};