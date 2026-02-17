class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
         TreeNode* temp=root;
         TreeNode* temp1=NULL;
         TreeNode* prev=NULL;
         while(root!=NULL){
           
             if(root->val>key){
                 prev=root;
                root=root->left;
             }
             else if(root->val<key){
                 prev=root;
                root=root->right;
             }
             else if(root->val==key){
                  temp1=root;
                  break;
             }
            
         }
         if(temp1==NULL){
            return temp;
         }
         if(temp1->left==NULL && temp1->right==NULL){
            if(prev==NULL){
                return NULL;
            }
            if(prev->left==temp1){
                prev->left=NULL;
            }
            else if(prev->right==temp1){
                prev->right=NULL;
            }
         }
         else if(temp1->right==NULL){
            if(prev==NULL){
                 return temp->left;
            }
            // FIXED: was hardcoded to prev->left
            if(prev->left==temp1) prev->left=temp1->left;
            else prev->right=temp1->left;
            return temp;
         }
         else if(temp1->left==NULL){
            if(prev==NULL){
                return temp->right;
            }
            // FIXED: was hardcoded to prev->left
            if(prev->left==temp1) prev->left=temp1->right;
            else prev->right=temp1->right;
            return temp;
         }

         else if(temp1->right!=NULL && temp1->left!=NULL){
            if(prev==NULL){
                TreeNode* temp2=temp1->left;
                TreeNode* temp3=temp1->right;
           
            temp1=temp1->right;
            while(temp1->left!=NULL){
                temp1=temp1->left;
            }
            temp1->left=temp2;
            return temp3;
            }
           
            TreeNode* temp2=temp1->left;
            // FIXED: was hardcoded to prev->left
            if(prev->left==temp1) prev->left=temp1->right;
            else prev->right=temp1->right;
            temp1=temp1->right;
            while(temp1->left!=NULL){
                temp1=temp1->left;
            }
            temp1->left=temp2;
            return temp;
         }

         return temp;
    }
};