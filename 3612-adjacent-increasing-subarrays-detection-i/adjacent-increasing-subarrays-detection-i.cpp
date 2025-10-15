class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt1=1;
        int cnt2=0;
        int i=1;
        while(i<nums.size()){
             if(cnt2==0){
                if(nums[i]>nums[i-1]){
                    cnt1+=1;
                }
                else{
                    if(cnt1>=k){
                    cnt2=1;}
                    else{
                        cnt1=1;
                    }
                }
             }
             else{
                 if(nums[i]>nums[i-1]){
                    cnt2+=1;
                 }
                 else{
                    cnt1=1;
                    cnt2=0;
                 }
             }

             if(cnt1 >= (2*k)){
                return true;
             }
             if(cnt1>=k && cnt2>=k){
                return true;
             }

             i+=1;
        }

        return false;
    }
};