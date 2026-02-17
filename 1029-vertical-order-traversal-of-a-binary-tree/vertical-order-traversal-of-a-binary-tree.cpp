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
        map<int,vector<pair<int,int>>> umap; 
        vector<vector<int>> ans;
     
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
              int row=0;
        while(!q.empty()){
            int sz=q.size();
      
            while(sz>0){
             pair<TreeNode*,int> p=q.front();
            
             umap[p.second].push_back({row,p.first->val});
        
             q.pop();
             if(p.first->left!=NULL){
                q.push({p.first->left,p.second-1});
             }
             if(p.first->right!=NULL){
                q.push({p.first->right,p.second+1});
             }
             sz-=1;
             
             }
            row+=1;
        }
        cout<<"\n";
        for(auto x:umap){
             vector<pair<int,int>> v=x.second;
             sort(v.begin(),v.end());
         
             vector<int> v1;
             for(int j=0;j<v.size();j++){
               
                
                 v1.push_back(v[j].second);

             }
        
             ans.push_back(v1);
        }
        return ans;
    }
};