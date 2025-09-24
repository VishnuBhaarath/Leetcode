class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long int ans=INT_MAX;
        long long int sum1=0;
        for(int i=0;i<nums.size();i++){
           if(i>0 && nums[i]==nums[i-1]) continue;
           int j=i+1;
           int k=n-1;
           while(j<k){
             long long int sum=nums[i]+nums[j]+nums[k];
             if(sum==target){
                  return sum;
             }
             else if(sum>target){
                 int val=abs(sum-target);
                 if(val<ans){
                    ans=val;
                    sum1=sum;
                 }
                 k-=1;
             }
             else{
                int val=abs(sum-target);
                 if(val<ans){
                    ans=val;
                    sum1=sum;
                 }
                j+=1;
             }
           }
        }
        return sum1;
    }
};