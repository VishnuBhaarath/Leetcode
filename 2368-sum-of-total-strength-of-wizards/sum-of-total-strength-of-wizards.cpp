class Solution {
public:
    int totalStrength(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;

        // ---------- ADDED: layer 1, prefix sums with a leading 0 ----------
        // psum[k] = arr[0] + ... + arr[k-1], size n+1
        vector<long long> psum(n+1,0);
        for(int i=0;i<n;i++){
            psum[i+1]=(psum[i]+arr[i])%mod;
        }

        // ---------- ADDED: layer 2, prefix sums of psum ----------
        // ppsum[k] = psum[0] + ... + psum[k-1], size n+2
        vector<long long> ppsum(n+2,0);
        for(int i=0;i<=n;i++){
            ppsum[i+1]=(ppsum[i]+psum[i])%mod;
        }

        // ---------- YOUR CODE, UNCHANGED ----------
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
        for(int i=0;i<r.size();i++){
            long long int l1=0;
            if(l[i]==-1){
                l1=i+1;
            }
            else{
                l1=(i-l[i]);
            }
            long long int r1=0;
            if(r[i]==-1){
                r1=(n-i);
            }
            else{
                r1=r[i]-i;
            }

            // ---------- CHANGED: was arr[i]*(l1*r1) ----------
            int L=l[i];                       // -1 if no smaller element on the left
            int R=r[i];
            if(R==-1) R=n;                    // n if no smaller-or-equal on the right

            // sum of psum[b+1] for b = i..R-1  ->  psum[i+1..R]
            long long rightPart=(ppsum[R+1]-ppsum[i+1]+mod)%mod;

            // sum of psum[a] for a = L+1..i    ->  psum[L+1..i]
            long long leftPart=(ppsum[i+1]-ppsum[L+1]+mod)%mod;

            // sum of all subarray sums where arr[i] is the minimum
            long long total=((l1*rightPart)%mod - (r1*leftPart)%mod + mod)%mod;

            long long val=(arr[i]*total)%mod; // arr[i] up to 1e9, total < mod: fits in long long

            sum+=val;
            sum%=mod;
        }

        return sum;
    }
};