// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
       stack<int> st;
       int ans=0;
       for(int i=0;i<s.size();i++){
           if(st.empty()){
               st.push(i);
           }
           else{
               if(s[i]=='('){
                   st.push(i);
               }
               else{
                   if(s[st.top()]==')'){
                       st.push(i);
                   }
                   else{
                      int tp=st.top();
                      st.pop();
                      int val=i-tp+1;
                      if(st.empty()){
                          val+=tp;
                      }
                      else{
                          int tp1=st.top();
                          val+=tp-tp1-1;
                      }
                      ans=max(ans,val);
                   }
               }
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends