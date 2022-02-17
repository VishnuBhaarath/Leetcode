class Solution {
public:
   
  
    vector<vector<int>> combine(int n, int k) {
        vector<int> v(n,0);
        vector<int> v1;
         vector<vector<int>> ans;
        backtrack(0,0,n,k,v1,ans);
        return ans;
    }
    void backtrack(int i, int cnt,int n,int k,vector<int> v1,vector<vector<int>>&ans){
       
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
         if((n-i+cnt)<k){
           
            return;
        }
       
        v1.push_back(i+1);
        
        backtrack(i+1,cnt+1,n,k,v1,ans);
       
        v1.pop_back();
        
        backtrack(i+1,cnt,n,k,v1,ans);
    }
};