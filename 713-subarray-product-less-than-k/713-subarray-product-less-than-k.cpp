class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int prod=1;
        int cnt=0;
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n){
            if((prod*nums[i])<k){
                prod=prod*nums[i];
                i+=1;
              }
            else{
               
                cnt+=(i-j);
               
                if(i!=j){
                prod=prod/nums[j];
                j+=1;}
                else{
                    i+=1;
                    j+=1;
                }
            }
        }
       
        int m=i-j;
        long long int sum=(m*(m+1))/2;
        cnt+=sum;
        return cnt;
    }
};