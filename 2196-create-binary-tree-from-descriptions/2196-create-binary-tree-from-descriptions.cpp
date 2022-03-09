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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,int> left;
        map<int,int> right;
        int parent=0;
        map<int,int> leaf;
        for(int i=0;i<descriptions.size();i++){
            if(descriptions[i][2]==1){
                left[descriptions[i][0]]=descriptions[i][1];
                leaf[descriptions[i][1]]+=1;
                
            }
            else{
                right[descriptions[i][0]]=descriptions[i][1];
                leaf[descriptions[i][1]]+=1;
            }
        }
      
        for(int i=0;i<descriptions.size();i++){
            if(leaf[descriptions[i][0]]==0){
                parent=descriptions[i][0];
                break;
            }
        }
        TreeNode* root=new TreeNode();
        root->val=parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tp=q.front();
          
            q.pop();
            if(left.find(tp->val)!=left.end()){
                TreeNode* temp=new TreeNode();
                temp->val=left[tp->val];
                cout<<left[tp->val];
                cout<<" ";
                tp->left=temp;
                temp->left=NULL;
                temp->right=NULL;
                q.push(temp);
            }
            if(right.find(tp->val)!=right.end()){
                TreeNode* temp=new TreeNode();
                temp->val=right[tp->val];
                cout<<right[tp->val];
                tp->right=temp;
                temp->left=NULL;
                temp->right=NULL;
                q.push(temp);
            }
           
        }
       
        return root;
    }
};