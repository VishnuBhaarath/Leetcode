class Solution {
public:
    int func1(vector<int> nums, int goal){
        int i=0;
        int j=0;
        int sum=0;
        int cnt=0;
        while(j<nums.size()){
           sum+=nums[j];
           if(sum<=goal){
             cnt+=(j-i)+1;
           }
           else{
            while(sum>goal){
                if(i<nums.size()){
                sum-=nums[i];
                i+=1;}
                else{
                    return 0;
                }
            }
            cnt+=(j-i)+1;
           }
           j+=1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum1=func1(nums,goal);
        int sum2=func1(nums,goal-1);
        
        return sum1-sum2;

    }
};