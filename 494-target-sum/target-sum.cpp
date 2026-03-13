class Solution {
public:
    int cnt=0;
    vector<vector<int>> dp;
    void func(int i,vector<int>& nums,int sum,int target){
        if(i==nums.size()){
         
            
            if(sum==target){
                cnt+=1;
            }
            return;
           
        }
         
       func(i+1,nums,sum+nums[i],target); 
        func(i+1,nums,sum-nums[i],target);

    }

    int findTargetSumWays(vector<int>& nums, int target) {
       // dp.resize(n,vector<int>(2002,0));
        func(0,nums,0,target);
        return cnt;
    }
};