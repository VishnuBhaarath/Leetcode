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
    int widthOfBinaryTree(TreeNode* root) {
         queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});  // Start from 0
        long long ans = 1;
        
        while(!q.empty()) {
            int sz = q.size();
            long long minIndex = q.front().second;  // Get leftmost index
            long long first = 0, last = 0;
            
            for(int i = 0; i < sz; i++) {
                auto [node, idx] = q.front();
                q.pop();
                
                // Normalize index relative to leftmost node
                long long normalizedIdx = idx - minIndex;
                
                if(i == 0) first = normalizedIdx;
                if(i == sz - 1) last = normalizedIdx;
                
                if(node->left) {
                    q.push({node->left, 2 * normalizedIdx + 1});
                }
                if(node->right) {
                    q.push({node->right, 2 * normalizedIdx + 2});
                }
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
};