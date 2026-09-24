class Solution {
public:
    vector<int> dp;
    int func(vector<int>& arr,int k,int i,int n){
        if(i==arr.size()){
            return 0;
        }

        int val=0;
        int ans=0;
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=i;j<min(i+k,n);j++){
           
            val=max(val,arr[j]);
            int sz=(j-i+1);
            ans=max(ans,(val*sz)+func(arr,k,j+1,n));
           
          
        }
        return dp[i]=ans;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        dp.resize(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int val=0;
            int ans=0;
            for(int j=i;j<min(i+k,n);j++){
           
            val=max(val,arr[j]);
            int sz=(j-i+1);
            ans=max(ans,(val*sz)+dp[j+1]);
           
          
        }
        dp[i]=ans;
        }
        return dp[0];
      return func(arr,k,0,n);
     
        return 84;
        
    }
};