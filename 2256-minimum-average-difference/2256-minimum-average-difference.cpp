class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            dp.push_back(dp[dp.size()-1]+nums[i]);
        }
       
        int n=nums.size();
        n-=1;
        long long int idx=-1;
        long long int ans=-1;
        for(int i=0;i<dp.size()-1;i++){
            double avg1=(dp[i]/(i+1));
            double avg2=(dp[dp.size()-1]-dp[i])/n;
            long long int val=abs(round(avg1)-round(avg2));
            if(ans==-1){
                ans=val;
                idx=i;
            }
            else if(val<ans){
                ans=val;
                idx=i;
            }
          
            n-=1;
        }
        double avg=dp[dp.size()-1]/dp.size();
        int val=round(avg);
        if(val<ans || ans==-1){
            return dp.size()-1;
        }
        return idx;
    }
};