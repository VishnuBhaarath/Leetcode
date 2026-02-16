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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        unordered_map<TreeNode*,int> left;
        unordered_map<TreeNode*,int> right;

        while(!st.empty()){

            while(st.top()->left!=NULL && left[st.top()]==0){
                left[st.top()]+=1;
                st.push(st.top()->left);
            }
            TreeNode* tp=st.top();
            ans.push_back(tp->val);
            st.pop();
            

            if(tp->right!=NULL && right[tp]==0){
                right[tp]+=1;
                st.push(tp->right);
            }
        }

        return ans;
    }
};