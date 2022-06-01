// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long maximumAmount(int nums[], int n){
        // Your code here
       
        int table[n][n];
        
        for(int k=0;k<n;k++){
            for(int i=0,j=k;j<n;i++,j++){
                int x=0;
                int y=0;
                int z=0;
                if((i+2<=j)){
                    x=table[i+2][j];
                }
                if((i+1<=j-1)){
                    y=table[i+1][j-1];
                }
                if(i<=j-2){
                    z=table[i][j-2];
                }
                table[i][j]=max(nums[i]+min(x,y),nums[j]+min(y,z));
            }
        }
        return table[0][n-1];
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends