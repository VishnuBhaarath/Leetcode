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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        map<int,vector<int>> umap;
        q.push({root, 0});
        umap[0].push_back(root->val);
        while (!q.empty()) {
            int sz = q.size();
            map<int,vector<int>> umap1;
            while (sz > 0) {
                pair<TreeNode*,int> p = q.front();
                q.pop();
                if (p.first->left != NULL) {
                    q.push({p.first->left, p.second - 1});
                    umap1[p.second-1].push_back(p.first->left->val);
                  //  umap[p.second-1].push_back(p.first->left->val);
                }
                if (p.first->right != NULL) {
                    q.push({p.first->right, p.second + 1});
                      //umap[p.second+1].push_back(p.first->right->val);
                       umap1[p.second+1].push_back(p.first->right->val);

                }

                sz -= 1;
            }
            for(auto x:umap1){
                vector<int> v=x.second;
                sort(v.begin(),v.end());
                for(int i=0;i<v.size();i++){
                    umap[x.first].push_back(v[i]);
                }
            }
        }
        
        vector<vector<int>> dp;
        for(auto x:umap){
            dp.push_back(x.second);
        }
       

        return dp;
    }
};