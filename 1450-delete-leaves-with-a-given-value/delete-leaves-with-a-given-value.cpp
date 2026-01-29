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
    TreeNode* prev;
    int l=0;
    void traversal(TreeNode* root,int target,int t){
        if(root==NULL){
            return;
        }
       
        if(root->val==target){
            if(root->left==NULL && root->right==NULL){
                if(t==0){
                    prev->left=NULL;
                }
                if(t==1){
                    prev->right=NULL;
                }
                 l=1;
                return;

            }
          
        }
      
        prev=root;
        traversal(root->left,target,0);
        prev=root;
        traversal(root->right,target,1);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        prev=root;
        TreeNode* temp=root;
        while(1){
        root=temp; 
        if(temp->val==target){
            if(temp->left==NULL && temp->right==NULL){
                return NULL;
            }
        }
        l=0;
        traversal(root,target,-1);
        
        if(l==0){
        return temp;
        }
        }
        return temp;
    }
};