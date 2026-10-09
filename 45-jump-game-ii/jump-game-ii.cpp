class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        int cnt=0;
        if(n==1){
            return 0;
        }
        int r=min(nums[0],n-1);
        int i=1;
        int r1=0;
        cnt+=1;
        while(i<=r){
            r1=max(r1,(i+nums[i]));
            if(i==n-1){
                return cnt;
            }
            if(i==r){
                r=r1;
                r=min(r,n-1);
                r1=0;
                cnt+=1;
            }
            i+=1;

        }


        return 2;
       
    }
};