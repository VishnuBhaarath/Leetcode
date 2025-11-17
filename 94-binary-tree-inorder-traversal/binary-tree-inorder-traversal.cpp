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
        if (root != NULL)
            st.push(root);

        while (!st.empty()) {
            TreeNode* tp = st.top();

            if (tp->left != NULL) {
                st.push(tp->left);

            } else {
                v.push_back(tp->val);
                st.pop();
                if (tp->right != NULL) {
                    st.push(tp->right);

                } else {
                    while (!st.empty()) {
                        if (st.top()->right == NULL) {
                            v.push_back(st.top()->val);
                            st.pop();
                        } else {
                            TreeNode* tp1 = st.top();
                            v.push_back(st.top()->val);
                            st.pop();
                            st.push(tp1->right);
                            break;
                        }
                    }
                }
            }
        }
        return v;
    }
};