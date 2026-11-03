class Solution {
public:
    void sortColors(vector<int>& nums) {
       int cnt0=0;
       int cnt1=0;
       int cnt2=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
         if(nums[i]==0){
            cnt0+=1;
         }
         if(nums[i]==1){
            cnt1+=1;
         }
         if(nums[i]==2){
            cnt2+=1;
         }
       }
       for(int i=0;i<nums.size();i++){
          if(cnt0>0){
            nums[i]=0;
            cnt0-=1;
          }
          else if(cnt1>0){
            nums[i]=1;
            cnt1-=1;
          }
          else if(cnt2>0){
            nums[i]=2;
            cnt2-=1;
          }
       }

    }
};