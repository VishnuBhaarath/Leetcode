class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
           
            if((nums[i]-prev)>k){
                cnt+=1;
                prev=nums[i];
            }
         
            
        }
        cnt+=1;
        return cnt;
    }
};