// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> s;
        vector<long long> v(n,-1);
        for(int i=0;i<arr.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else{
                if(arr[s.top()]>=arr[i]){
                    s.push(i);
                }
                else{
                    while(!s.empty()){
                        if(arr[s.top()]>=arr[i]){
                           
                            break;
                        }
                        v[s.top()]=arr[i];
                        s.pop();
                    }
                    s.push(i);
                }
            }
        }
        return v;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends