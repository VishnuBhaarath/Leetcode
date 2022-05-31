// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(),Arr.end());
        if(N==1){
            return 1;
        }
        
        long long int sum1=0;
        long long int sum2=Arr[N-1];
        for(int i=0;i<N-1;i++){
            sum1+=Arr[i];
            
        }
        long long int cnt=1;
        long long int j=N-2;
        while(sum2<=sum1){
            sum2+=Arr[j];
            sum1-=Arr[j];
            j-=1;
            
            cnt+=1;
            if(j<0){
                break;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends