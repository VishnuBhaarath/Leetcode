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
    TreeNode* deleteNode(TreeNode* root, int val) {
        

          TreeNode* temp1=root;
          TreeNode* prev=root;
          TreeNode* temp=NULL;
          if(root==NULL){
            return NULL;
          }
       
        while(root!=NULL){
             if(root->val<val){
                prev=root;
                root=root->right;
             }
             else if(root->val>val){
                 prev=root;
                 root=root->left;
             }
             else if(root->val==val){
                temp=root;
                break;

             }
        }

        if(temp1->val==val){
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            else if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            else{
                TreeNode * temp2=temp->left;
                TreeNode * temp3=temp;
                temp=temp->right;
                TreeNode* temp4=temp;

                while(temp->left!=NULL){
                    temp=temp->left;
                }
                temp->left=temp2;
                return temp4;
            }
        }
        
        if(temp!=NULL){
           
           
            if(temp->left==NULL && temp->right==NULL){
                if(prev->left==temp){
                    prev->left=NULL;
                }
                else if(prev->right==temp){
                    prev->right=NULL;
                }
            }
            else if(temp->left==NULL){
                if(prev->left==temp){
                    prev->left=temp->right;
                }
                else if(prev->right==temp){
                    prev->right=temp->right;
                }
            }
            else if(temp->right==NULL){
 if(prev->left==temp){
                    prev->left=temp->left;
                }
                else if(prev->right==temp){
                    prev->right=temp->left;
                }
            }
            else{
                TreeNode * temp2=temp->left;
                TreeNode * temp3=temp;
                temp=temp->right;
                TreeNode* temp4=temp;

                while(temp->left!=NULL){
                    temp=temp->left;
                }
                temp->left=temp2;
                if(prev->left==temp3){
                    prev->left=temp4;
                }
                else if(prev->right==temp3){
                    prev->right=temp4;
                }


            }
        }
        return temp1;
    }
};