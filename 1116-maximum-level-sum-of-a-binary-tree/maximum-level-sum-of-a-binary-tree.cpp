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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MIN;
        int lvl=0;
        int l=1;
        while(!q.empty()){
            int sz=q.size();
            int i=0;
            int data=0;
 
            while(i<sz){
                TreeNode* tp=q.front();
                data+=tp->val;
                q.pop();
                if(tp->left!=NULL){
                    q.push(tp->left);
                }
                if(tp->right!=NULL){
                    q.push(tp->right);
                }
                i+=1;
            }
            if(data>ans){
                ans=data;
                lvl=l;
            }
            l+=1;
            
        }
        return lvl;
    }
};