class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                candidate=nums[i];
                cnt=1;
            }
            else{
                if(candidate==nums[i]){
                    cnt+=1;
                }
                else{
                    cnt-=1;
                }
            }
        }
        return candidate;
    }
};