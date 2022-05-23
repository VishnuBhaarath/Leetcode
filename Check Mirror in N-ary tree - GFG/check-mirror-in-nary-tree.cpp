// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        map<int,vector<int>> umap;
        int i=0;
        while(i<(2*e)){
            umap[A[i]].push_back(A[i+1]);
            i+=2;
        }
        i=0;
        map<int,vector<int>> umap1;
        while(i<(2*e)){
            umap1[B[i]].push_back(B[i+1]);
            i+=2;
        }
        for(auto x:umap){
            vector<int> v=x.second;
            vector<int> v1=umap1[x.first];
            if(v.size()!=v1.size()){
                return 0;
            }
            else{
                int m=v.size();
                int j=m-1;
                int k=0;
                for(int k=0;k<m;k++){
                    if(v[k]!=v1[j]){
                        return 0;
                    }
                    j-=1;
                }
            }
            
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends