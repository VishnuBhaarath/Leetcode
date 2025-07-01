class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      map<int,int> psum;
      psum[0]+=1;
      int sum=0;
      int cnt=0;
      for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==goal){
             cnt+=psum[0];
        }
        else if(sum>goal){
            cnt+=psum[sum-goal];
        }
        psum[sum]+=1;
        
      }
  
      return cnt;
    }
};