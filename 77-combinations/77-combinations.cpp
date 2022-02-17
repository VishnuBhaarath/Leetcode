class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>,int> umap;
    vector<vector<int>> combine(int n, int k) {
        vector<int> v(n,0);
        vector<int> v1;
        backtrack(0,0,n,k,v1);
        return ans;
    }
    void backtrack(int i, int cnt,int n,int k,vector<int> v1){
        if((n-i+cnt)<k){
           
            return;
        }
        if(cnt>k){
          
            return;
        }
        if(cnt==k){
           
                ans.push_back(v1);
          
            return;
        }
        if(i==n){
            return;
        }
       
        v1.push_back(i+1);
        
        backtrack(i+1,cnt+1,n,k,v1);
       
        v1.pop_back();
        
        backtrack(i+1,cnt,n,k,v1);
    }
};