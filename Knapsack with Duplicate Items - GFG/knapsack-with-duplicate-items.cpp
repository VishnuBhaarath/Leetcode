// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> v(W+1,0);
        int ans=-1;
        for(int i=0;i<N;i++){
            for(int j=0;j<v.size();j++){
                if(wt[i]<=j){
                    if(wt[i]==j){
                        v[j]=max(v[j],val[i]);
                    }
                    else{
                        if(v[j-wt[i]]!=0){
                            v[j]=max(v[j],v[j-wt[i]]+val[i]);
                        }
                    }
                }
                ans=max(ans,v[j]);
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
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends