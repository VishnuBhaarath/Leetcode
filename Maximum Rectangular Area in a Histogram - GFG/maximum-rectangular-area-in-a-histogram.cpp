// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        // Your code here
        
         stack<long long int> st;
        long long int ans=0;
        for(int i=0;i<n;i++){
            if(st.empty()){
               st.push(i);
            }
            else{
               
              
                    while(heights[i]<heights[st.top()]){
                        int tp=st.top();
                        st.pop();
                        int w=0;
                        if(st.empty()){
                            w=i;
                        }
                        else{
                            int tp1=st.top();
                            w=i-tp1-1;
                        }
                       
                        long long int area=heights[tp]*w;
                        
                        ans=max(ans,area);
                        if(st.empty()){
                            break;
                        }
                        
                    }
                    st.push(i);
                
            }
        }
      
        while(!st.empty()){
            int tp=st.top();
            st.pop();
            int w=n-tp;
            if(!st.empty()){
                w+=(tp-st.top()-1);
            }
            else{
                w+=tp;
            }
            long long int area=heights[tp]*w;
         
            ans=max(ans,area);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends