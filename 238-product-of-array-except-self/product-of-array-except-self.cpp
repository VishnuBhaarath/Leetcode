class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt=0;
        long long int prod=1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt+=1;
            }
            else{
                prod=prod*nums[i];
            }
        }
     //   int n=nums.size();
        vector<int> v(n,0);
        if(cnt>=2){
            return v;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                long long int val=prod/nums[i];
                if(cnt==0){
                    v[i]=val;
                }
            
            }
            else{
                 v[i]=prod;
            }
        }
return v;
    }
};