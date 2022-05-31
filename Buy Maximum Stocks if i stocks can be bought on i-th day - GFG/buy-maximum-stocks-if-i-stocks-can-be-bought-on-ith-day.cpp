// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({price[i],i+1});
        }
        int cnt=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            pair<int,int> p=v[i];
            int c=p.first;
            int val=p.second;
            int q=k/c;
            if(q>val){
                k-=(val*c);
                cnt+=val;
            }
            else{
                k-=(q*c);
                cnt+=q;
            }
            
        }
        return cnt;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends