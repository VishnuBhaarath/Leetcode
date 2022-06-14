// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<int> v;
        v.push_back(grid[0][0]);
        backtrack(0,0,grid,v,n,m);
        return ans;
    }
    void backtrack(int i,int j, vector<vector<int>>grid,vector<int> v,int n,int m){
        if((i==n-1) &&(j==m-1)){
            ans.push_back(v);
            return;
         }
       
        if((i+1)<n){
            v.push_back(grid[i+1][j]);
            backtrack(i+1,j,grid,v,n,m);
            v.pop_back();
        }
        if((j+1)<m){
            v.push_back(grid[i][j+1]);
            backtrack(i,j+1,grid,v,n,m);
            v.pop_back();
        }
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends