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
        int ans = 0;
    
    void traversal(TreeNode* root, int curr) {
        if (!root) return;
        
        curr = (curr << 1) | root->val;  // shift left and add current bit
        
      
        
        traversal(root->left, curr);
        traversal(root->right, curr);
          if (!root->left && !root->right) {
            ans += curr;
            //return;
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        traversal(root, 0);
        return ans;
    }
};