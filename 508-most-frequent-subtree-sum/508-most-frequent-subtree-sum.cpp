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
    map<int,int> umap;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int ans=0;
        sum(root,ans);
        vector<int> v;
        for(auto x:umap){
            if(x.second==ans){
                v.push_back(x.first);
            }
        }
       
        return v;
    }
    int sum(TreeNode* root,int& ans){
        if(root==NULL){
            return 0;
        }
        int org=root->val;
        int lh=sum(root->left,ans);
        int rh=sum(root->right,ans);
        if(root->left!=NULL || root->right!=NULL){
        umap[lh+rh+org]+=1;
        ans=max(ans,umap[lh+rh+org]);
        }
        else{
            umap[root->val]+=1;
            ans=max(ans,umap[root->val]);
        }
        return lh+rh+org;
    }
};