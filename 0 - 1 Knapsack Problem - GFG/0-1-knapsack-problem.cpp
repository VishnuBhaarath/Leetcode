// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int>v(W+1,0);
       vector<vector<int>> dp(n+1,v);
       
       for(int i=1;i<dp.size();i++){
           for(int j=1;j<dp[0].size();j++){
             
               if(wt[i-1]>j){
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
               else if(wt[i-1]<j){
                   int x=max(dp[i-1][j],dp[i][j-1]);
                   int temp=val[i-1]+dp[i-1][j-wt[i-1]];
                   dp[i][j]=max(temp,x);
               }
               else{
                   int x=max(dp[i-1][j],dp[i][j-1]);
                   int temp=val[i-1]+dp[i-1][j-wt[i-1]];
                   dp[i][j]=max(temp,x);
               }
           }
          
       }
       
      
       return dp[n][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends