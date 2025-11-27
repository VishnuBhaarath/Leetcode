/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int check(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return 0;
        }
        if(root->val==p->val || root->val==q->val){
            return 1;
        }
        return check(root->left,p,q) || check(root->right,p,q);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* tp= st.top();
            st.pop();
            int l=0;
            int r=0;
            l=check(tp->left,p,q);
            r=check(tp->right,p,q);
            if(tp->val==p->val || tp->val==q->val){
                return tp;
            }
            if(l==1 && r==1){
                return tp;
            }
            else if(l==1){
                
                st.push(tp->left);
            }
            else if(r==1){
               
                st.push(tp->right);
            }
        }
        return root;
    }
};