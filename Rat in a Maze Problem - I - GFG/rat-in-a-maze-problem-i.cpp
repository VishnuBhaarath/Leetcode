// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> v;
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string temp="";
        map<pair<int,int>,int> umap;
        if(m[0][0]==1){
        backtrack(0,0,m,n,temp,umap);}
        return v;
    }
    void backtrack(int i,int j,vector<vector<int>>m,int n,string temp,map<pair<int,int>,int> umap){
       
        if((i==(n-1)) && (j==(n-1))){
            v.push_back(temp);
            return;
        }
        umap[{i,j}]=1;
        if((i+1)<n){
            if(m[i+1][j]==1){
                if(umap[{i+1,j}]==0){
                  
                  temp+="D";
               
                  backtrack(i+1,j,m,n,temp,umap);
               
            
                
                  temp.pop_back();
                    
                }
            }
        }
        if((j+1)<n){
            if(m[i][j+1]==1){
                if(umap[{i,j+1}]==0){
                    
                    temp+="R";
                 
                    backtrack(i,j+1,m,n,temp,umap);
                     
                    
                    temp.pop_back();
                }
            }
        }
        
        if((i-1)>=0){
            if(m[i-1][j]==1){
                if(umap[{i-1,j}]==0){
                    temp+="U";
                  
                    backtrack(i-1,j,m,n,temp,umap);
                  
                  
                    temp.pop_back();
                }
            }
        }
        
        if((j-1)>=0){
            if(m[i][j-1]==1){
                if(umap[{i,j-1}]==0){
                  
                    temp+="L";
                
                    backtrack(i,j-1,m,n,temp,umap);
                      
                     
                   
                    temp.pop_back();
                }
            }
        }
        umap[{i,j}]=0;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends