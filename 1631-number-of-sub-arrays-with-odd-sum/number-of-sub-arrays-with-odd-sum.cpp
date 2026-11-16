class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       
        long long odd=0;
        long long even=1;
        long long sum=0;
        long long cnt=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                cnt+=odd;
                even+=1;
            }
            else{

                cnt+=even;
                odd+=1;
            }
            cnt%=mod;
        }
        return cnt;
    }
};