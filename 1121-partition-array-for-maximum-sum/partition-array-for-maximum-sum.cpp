class Solution {
public:
   int ans=0;
   int check(vector<int>& arr, int i, int j){
    
     int val=arr[i];
     for(int k=i;k<j;k++){
        val=max(val,arr[k]);
     }
     return (j-i)*val;

   }
   void func(vector<int>& arr, int k,int i,int sum){
      if(i==arr.size()){
       ans=max(ans,sum);
        return;
      }
      int n=arr.size();
      int val1=-1;
      for(int j=i+1;j<min(n+1,i+k+1);j++){
        
           val1=max(val1,arr[j-1]);
           int val2=val1*(j-i);
          
         // int val=check(arr,i,j);
         func(arr,k,j,sum+val2);
      }
   }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
       // vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
       // func(arr,k,0,0);
       vector<int> dp(n+1,0);
       dp[n-1]=arr[n-1];
       for(int i=n-2;i>=0;i--){
          int val=0;
          int ans=0;
         for(int j=i;j<min(n,i+k);j++){
             val=max(val,arr[j]);
             int sum=(j-i+1)*val;
             int temp=0;
             if(j+1<n){
                temp+=dp[j+1];
             }
             ans=max(ans,sum+temp);
             dp[i]=max(dp[i],ans);

         }
       }
       for(int i=0;i<dp.size();i++){
        cout<<dp[i];
        cout<<" ";
       }
       cout<<"\n";
        return dp[0];
    }
};