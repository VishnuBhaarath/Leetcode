// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=0){
                    int val=matrix[i-1][j];
                    if((j-1)>=0){
                        val=max(val,matrix[i-1][j-1]);
                    }
                    if((j+1)<m){
                        val=max(val,matrix[i-1][j+1]);
                    }
                    matrix[i][j]+=val;
                }
                if(i==(N-1)){
                    ans=max(ans,matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends