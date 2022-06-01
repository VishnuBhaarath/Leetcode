class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        
        long long sum=nums[0];
        int prev=nums[0];
        int sign=-1;
        for(int i=1;i<nums.size();i++){
         
            if(sign==-1){
                if(nums[i]>=prev){
                    sum-=prev;
                    prev=nums[i];
                    sum+=nums[i];
                }
                else{
                    sum-=nums[i];
                    prev=nums[i];
                    sign=1;
                }
            }
            else if(sign==1){
                if(nums[i]<=prev){
                    sum+=prev;
                    prev=nums[i];
                    sum-=nums[i];
                }
                else{
                    sum+=nums[i];
                    prev=nums[i];
                    sign=-1;
                    
                }
            }
        }
        if(sign==1){
            sum+=prev;
        }
        return sum;
    }
};