// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n==1){
	        return arr[0];
	    }
	    if(n==2){
	        return max(arr[0],arr[1]);
	    }
	    int ans=0;
	    for(int i=1;i<n;i++){
	        if(i==1){
	            arr[i]=max(arr[i],arr[0]);
	            ans=max(ans,arr[i]);
	        }
	        else{
	        arr[i]=max(arr[i-1],arr[i-2]+arr[i]);
	        ans=max(ans,arr[i]);}
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends