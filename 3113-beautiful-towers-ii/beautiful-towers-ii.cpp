class Solution {
public:
    long long maximumSumOfHeights(vector<int>&  heights) {
          stack<int> st;
        st.push(-1);
        long long int total=0;
        long long int n=heights.size();
        vector<long long int> v(n,0);
        for(int i=0;i<heights.size();i++){
            
            if(st.top()!=-1 && heights[st.top()]<=heights[i]){

            }
            else{
             while(st.top()!=-1 && heights[st.top()]>heights[i]){
                    long long int tp=st.top();
                    st.pop();
                    long long int tp1=st.top();
                   long long int w=(tp-tp1);
                    total-=(w*heights[tp]);
            }
            }
            

           long long  int tp=st.top();
           long long  int w=(i-tp);
            total+=(w*heights[i]);
            v[i]=total;
            st.push(i);
        }

        
        vector<long long int> v1(n,0);
        reverse(heights.begin(),heights.end());
        stack<long long int> st1;
        st1.push(-1);
total=0;
         for(long long int i=0;i<n;i++){
            
            if(st1.top()!=-1 && heights[st1.top()]<=heights[i]){

            }
            else{
             while(st1.top()!=-1 && heights[st1.top()]>heights[i]){
                    long long int tp=st1.top();
                    st1.pop();
                    long long int tp1=st1.top();
                    long long int w=(tp-tp1);
                     
                    total-=(w*heights[tp]);
                  
                   
            }
            }
            
           
           long long int tp=st1.top();
            long long int w=(i-tp);
           
            total+=(w*heights[i]);
           
            v1[i]=total;
            st1.push(i);
        }

        
        long long ans=0;
        for(int i=0;i<n;i++){
            long long val=v[i]+v1[n-1-i]-heights[n-1-i];
            ans=max(ans,val);
        }

        return ans;
    }
};