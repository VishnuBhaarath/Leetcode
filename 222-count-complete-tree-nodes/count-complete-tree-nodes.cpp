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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=lheight(root->left);
        int rh=rheight(root->right);
        cout<<root->val;
        cout<<" ";
        cout<<lh;
        cout<<" ";
        cout<<rh;
        cout<<"\n";
        if(lh==rh){
           int val=pow(2,lh)-1;
           return val;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int lheight(TreeNode* root){
         int cnt=1;
         while(root!=NULL){
            cnt+=1;
            root=root->left;
         }
         return cnt;
    }

    int rheight(TreeNode* root){
        int cnt=1;
        while(root!=NULL){
            cnt+=1;
            root=root->right;
        }
        return cnt;
    }
};