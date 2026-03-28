class Solution {
public:
    int ans=INT_MIN;
    vector<int> dp;
    int func(vector<int>& arr,int i,int k,int n){
        
        if(i==n){
           
            
            return 0;
        }
       if(dp[i]!=-1){
        return dp[i];
       }
       int val=-1;
       int ans=-1;
       for(int j=i;j< min(n,(i+k));j++){
          
          val=max(val,arr[j]);
          int sz=(j-i+1);
          int val1=sz*val;
          int sum= val1+func(arr,j+1,k,n);
          ans=max(ans,sum);
       //   sum+=(val*sz);
          
         
         // sum-=(val*sz);
       }
return dp[i]=ans;
         
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        dp.resize(n+1,0);

   //   func(arr,0,k,n);
        for(int i=0;i<dp.size();i++){
            cout<<dp[i];
            cout<<" ";
        }
        cout<<"\n";

        for(int i=n-1;i>=0;i--){
            int val=-1;
            int ans=-1;
            for(int j=i;j<min(n,i+k);j++){
 val=max(val,arr[j]);
          int sz=(j-i+1);
          int val1=sz*val;
          int sum=val1+dp[j+1];
          ans=max(ans,sum);

            }
            dp[i]=ans;
        }
           for(int i=0;i<dp.size();i++){
            cout<<dp[i];
            cout<<" ";
        }
        cout<<"\n";
      return dp[0];
    }
};