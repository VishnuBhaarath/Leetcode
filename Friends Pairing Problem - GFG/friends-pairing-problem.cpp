// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long long int mod=1e9+7; 
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 4;
        }
        if(n==4){
            return 10;
        }
        vector<long long int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        dp[4]=10;
        for(long long int i=5;i<=n;i++){
            dp[i]=(dp[i-1]%mod)+((i-1)*dp[i-2])%mod;
            dp[i]=dp[i]%mod;
        }
        return dp[n];
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends