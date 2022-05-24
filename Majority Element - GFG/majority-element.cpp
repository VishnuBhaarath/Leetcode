// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
         int cand=a[0];
         int cnt=1;
         for(int i=1;i<size;i++){
             if(cnt==0){
                 cand=a[i];
                 cnt=1;
             }
             else{
                 if(cand==a[i]){
                     cnt+=1;
                 }
                 else{
                     cnt-=1;
                 }
             }
         }
         cnt=0;
         for(int i=0;i<size;i++){
             if(cand==a[i]){
                 cnt+=1;
             }
         }
         if(cnt>(size/2)){
             return cand;
         }
         return -1;
        // your code here
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends