class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        stack<int> s;
        s.push(0);
        for(int i=1;i<arr.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else if(arr[i]>arr[s.top()]){
                  left[i]=s.top();
                  s.push(i);
            }
            else{
                while(arr[i]<=arr[s.top()]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(!s.empty()){
                    left[i]=s.top();
                }
                s.push(i);
            }
        }

        stack<int> s1;
        s1.push(n-1);

        for(int i=n-2;i>=0;i--){
            if(s1.empty()){
                s1.push(i);
            }
            else if(arr[i]>=arr[s1.top()]){
                
                right[i]=s1.top();
                s1.push(i);
            }
            else{
                while(arr[i]<arr[s1.top()]){
                    s1.pop();
                    if(s1.empty()){
                        break;
                    }
                }
                if(!s1.empty()){
                    right[i]=s1.top();
                }
                s1.push(i);
            }
        }
       
        long long int ans=0;
        long long int mod=1e9+7;

        for(int i=0;i<arr.size();i++){
            if(left[i]==-1 && right[i]==-1){
                ans+=(long long)(arr[i])*(long long)(i+1)*(long long)(n-i);
                ans%=mod;
            }
            else {
                int l=left[i];
                int r=right[i];
                if(r!=-1 && l!=-1){
                    ans+=(long long)(arr[i])*(long long)(i-l)*(long long)(r-i);
                    ans%=mod;
                }
                else if(l==-1){
                    ans+=(long long)(arr[i])*(long long)(i+1)*(long long)(r-i);
                    ans%=mod;
                }
                else if(r==-1){
                    ans+=(long long)(arr[i])*(long long)(i-l)*(long long)(n-i);
                    ans%=mod;
                }
            }
           
        }
        return ans;
    }
};