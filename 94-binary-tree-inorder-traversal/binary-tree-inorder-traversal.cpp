/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        if(root!=NULL)
        st.push(root);
        map<TreeNode*,int> umap;
        while (!st.empty()) {
            TreeNode* tp = st.top();
            
            if(tp->left!=NULL && umap[tp->left]==0){
                st.push(tp->left);
                umap[tp->left]=1;
            }
            else{
                v.push_back(tp->val);
                st.pop();
                if(tp->right!=NULL && umap[tp->right]==0){
                     st.push(tp->right);
                     umap[tp->right]=1;
                }
            }
        }
        return v;
    }
};