// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int j=arr[0];
        int cnt=1;
        int ans=j;
        if(n==1){
            return 0;
        }
        if(ans>=(n-1)){
            return 1;
        }
        for(int i=0;i<=j;i++){
            int val=i+arr[i];
            ans=max(ans,val);
            if(ans>=(n-1)){
                cnt+=1;
                return cnt;
            }
            if(i==j){
                j=ans;
                cnt+=1;
            }
        }
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends