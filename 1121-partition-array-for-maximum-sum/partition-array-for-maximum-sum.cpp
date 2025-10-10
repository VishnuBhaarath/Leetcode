class Solution {
public:
    int func1(int i,int j,vector<int>&arr){
        int ans=arr[i];
        while(i<=j){
            ans=max(ans,arr[i]);
            i+=1;
        }
        return ans;

    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n=arr.size();
       vector<int> dp(n+1,0); 


       for(int i=n-1;i>=0;i--){
        int ans=INT_MIN;
      
        for(int j = i; j < std::min(i+k, (int)(arr.size())); j++){
           
            int sum=(j-i+1)*func1(i,j,arr)+dp[j+1];
         
            ans=max(ans,sum);
        }
       
        dp[i]=ans;
      }
     
       return dp[0];
      
    }
};