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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> umap;
        queue<pair<TreeNode*,int>> q;
        if(root!=NULL){
            q.push({root,0});
        }
       
        while(!q.empty()){
            int sz=q.size();
            map<int,priority_queue<int,vector<int>,greater<int>>> umap1;
            while(sz>0){
                pair<TreeNode*,int> p=q.front();
                q.pop();
                umap1[p.second].push(p.first->val);
                if(p.first->left!=NULL){
                    q.push({p.first->left,p.second-1});
                }
                if(p.first->right!=NULL){
                    q.push({p.first->right,p.second+1});
                }
                sz-=1;
            }
            for(auto x:umap1){
                 priority_queue<int,vector<int>,greater<int>> pq=x.second;
                 while(!pq.empty()){
                     umap[x.first].push_back(pq.top());
                     pq.pop();
                 }
            }
            


        }
        vector<vector<int>> ans;
        for(auto x:umap){
            cout<<x.first;
            cout<<"\n";
            vector<int> v=x.second;
            ans.push_back(v);
        }
        
        return ans;
    }
};