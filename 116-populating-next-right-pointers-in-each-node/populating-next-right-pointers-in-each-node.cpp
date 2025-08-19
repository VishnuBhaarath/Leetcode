/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        queue<pair<Node*,int>> q;
        vector<vector<Node*>> dp;
        if(root!=NULL){
            
        }
        else{
            return root;
        }
        Node* temp=root;
        q.push({root,0});
        int cnt=0;
        vector<Node* > v;
        dp.push_back({root});
        while(q.size()!=0){
            Node* tp=q.front().first;
            int h=q.front().second;
            if(tp->left!=NULL){

              
                if(h==cnt){
                  v.push_back(tp->left);
                 
                }
                else{
                    dp.push_back(v);
                    v.clear();
                    v.push_back(tp->left);
                    cnt+=1;
                }
                
            }
            if(tp->right!=NULL){
               
                 if(h==cnt){
                  v.push_back(tp->right);
                 
                }
                else{
                     dp.push_back(v);
                    v.clear();
                    v.push_back(tp->right);
                    cnt+=1;
                }
            }
            if(tp->left!=NULL)
            q.push({tp->left,q.front().second+1});
            if(tp->right!=NULL)
            q.push({tp->right,q.front().second+1});
            q.pop();
        }
        if(v.size()!=0){
            dp.push_back(v);
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                Node* val= dp[i][j];
                if(j+1<dp[i].size()){
                    val->next=dp[i][j+1];
                }
            }
        }
        return temp;
    }
};