class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> l(n,-1);
        vector<int> r(n,-1);

        stack<int> s;
        for(int i=0;i<arr.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else{
                if(arr[s.top()]<arr[i]){
                    s.push(i);
                }
                else{
                    while(arr[s.top()]>=arr[i]){
                        l[s.top()]=i;
                        s.pop();
                        if(s.empty()){
                            break;
                        }
                    }
                    s.push(i);
                }
            }
        }

      
        stack<int> s1;
        for(int i=n-1;i>=0;i--){
            if(s1.empty()){
                s1.push(i);
            }
            else{
                if(arr[s1.top()]<=arr[i]){
                    s1.push(i);
                }
                else{
                    while(arr[s1.top()]>arr[i]){
                        r[s1.top()]=i;
                        s1.pop();
                        if(s1.empty()){
                            break;
                        }
                    }
                    s1.push(i);
                }
            }
        }
        long long sum=0;
        int mod=1e9+7;
       

        for(int i=0;i<l.size();i++){
            if(l[i]!=-1){
                long long count=(i-r[i])*(l[i]-i);
                sum=(sum+ (count*arr[i]));
                sum%=mod;
            }
            else{
                long long count=(i-r[i])*(n-i);
                sum=(sum+(count*arr[i]));
                sum%=mod;
            }
        }

        return sum;
    }
};