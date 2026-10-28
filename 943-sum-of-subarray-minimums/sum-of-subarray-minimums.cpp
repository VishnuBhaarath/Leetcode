class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                st.push(i);
            }
            else if(arr[i]>arr[st.top()]){
                int tp=st.top();
                l[i]=tp;
                st.push(i);
                //st.push(i);
            }
            else{
                while(arr[i]<=arr[st.top()]){
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                }
                if(!st.empty()){
                    l[i]=st.top();
                }
                st.push(i);
            }
        }

       
       
        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }
            else if(arr[i]>=arr[st.top()]){
                int tp=st.top();
                r[i]=tp;
                st.push(i);
                //st.push(i);
            }
            else{
                while(arr[i]<arr[st.top()]){
                    st.pop();
                    if(st.empty()){
                        break;
                    }
                }
                if(!st.empty()){
                    r[i]=st.top();
                }
                st.push(i);
            }

        }

         long long sum=0;
         int mod=1e9+7;
        for(int i=0;i<r.size();i++){
            long long int l1=0;
            if(l[i]==-1){
                l1=i+1;
            }
            else{
                l1=(i-l[i]);
               // l1+=1;
            }
            long long int r1=0;
            if(r[i]==-1){
                r1=(n-i);
            }
            else{
                r1=r[i]-i;
            }
            long long val=arr[i]*(l1*r1);
          
            sum+=val;
            sum%=mod;
            
        }
       

        return sum;
    }
};