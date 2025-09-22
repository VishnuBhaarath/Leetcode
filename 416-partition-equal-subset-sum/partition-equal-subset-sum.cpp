class Solution {
public:
   
    bool canPartition(vector<int>& arr) {
         int n=arr.size();
         int m=0;
         for(int i=0;i<arr.size();i++){
            m+=arr[i];
         }
         if((m%2)!=0){
            return false;
         }

         int val=m/2;
        
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==(n-1)){
                   
                    dp[i][arr[i]]=1;
                }
                else{
                    if(dp[i+1][j]==1){
                        dp[i][j]=1;
                        dp[i][j+arr[i]]=1;
                        if((j+arr[i]) ==val){
                         
                           return true;
                        }
                    }
                    if((arr[i]) ==val){
                   
                        return true;
                    }
                    dp[i][arr[i]]=1;
                }
            }
        } 
        if(dp[0][val]==1){
            return true;
        }
        
         return false;
    }
};