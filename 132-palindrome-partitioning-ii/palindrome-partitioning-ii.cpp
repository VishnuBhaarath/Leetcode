class Solution {
public:
    int ans=0;
    vector<int> dp;
     vector<vector<bool>> isPalin;
  
    int func(string &s,int i){
        if(i==s.size()){
        
          
     
            return -1; 
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string st="";
        int ans1=INT_MAX;
        for(int j=i;j<s.size();j++){
            
             if(isPalin[i][j]){
                int sum=1+func(s,j+1);
                ans1=min(ans1,sum);
             }
        }
        return dp[i]=ans1;
    }
    int minCut(string s) {


        ans=s.size();
        int n=s.size();
        dp.resize(n,-1);


          // Precompute palindrome table
          isPalin.resize(n,vector<bool>(n, false));
   
    
    // Every single character is a palindrome
    for(int i = 0; i < n; i++) {
        isPalin[i][i] = true;
    }
    
    // Check for length 2+
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if(s[i] == s[j]) {
                isPalin[i][j] = (len == 2) ? true : isPalin[i+1][j-1];
            }
        }
    }
    
        return min(ans,func(s,0));
       // return ans;
    }
};