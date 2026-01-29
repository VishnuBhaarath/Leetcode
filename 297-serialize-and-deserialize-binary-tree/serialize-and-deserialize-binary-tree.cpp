/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* temp=root;
         vector<TreeNode*> v;
        if(root!=NULL){
        v.push_back(root);
        q.push(root);}
       
        while(!q.empty()){
            TreeNode* tp=q.front();
            q.pop();
            if(tp->left!=NULL){
                q.push(tp->left);
            }
            v.push_back(tp->left);
            if(tp->right!=NULL){
                q.push(tp->right);
            }
            v.push_back(tp->right);

        }
        string ans="";
        for(int i=0;i<v.size();i++){
            if(v[i]!=NULL){
             
                ans+=to_string(v[i]->val)+ ",";
             
            }
            else{
             
                ans+="N,";
            }
        }
        cout<<ans;
        cout<<"\n";



        root=temp;
        if (!root) return "N";
        string res;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (!node) {
                res += "N,";
            } else {
                res += to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        cout<<res;
        cout<<"\n";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
string temp = "";

for (int i = 0; i < data.size(); i++) {
    if (data[i] != ',') {
        temp += data[i];  
    } else {
        v.push_back(temp);  
        temp = "";         
    }
}
cout<<data;
        cout<<"\n";
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            cout<<" ";
        }
        cout<<"\n";
        if(v.size()==0){
            return NULL;
        }
        TreeNode* t =new TreeNode();
        t->val=stoi(v[0]);
        TreeNode* root=t;
        queue<TreeNode*> q;
        q.push(t);
        int i=1;
        while(!q.empty()){
             TreeNode* tp=q.front();
             q.pop();
             if(v[i]=="N"){
                tp->left=NULL;
                i+=1;
             }
             else{
                TreeNode* t1 =new TreeNode();
                 t1->val=stoi(v[i]);
                 q.push(t1);
                 tp->left=t1;
                 i+=1;
             }


             if(v[i]=="N"){
                tp->right=NULL;
                i+=1;
             }
             else{
                TreeNode* t1 =new TreeNode();
                 t1->val=stoi(v[i]);
                 q.push(t1);
                 tp->right=t1;
                 i+=1;
             }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));