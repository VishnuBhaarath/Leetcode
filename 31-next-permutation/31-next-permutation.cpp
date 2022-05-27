class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int prev=n-1;
        int i=n-1;
        int idx=-1;
        while(i>=0){
            if(nums[i]>nums[prev]){
                prev=i;
            }
            else if(nums[i]<nums[prev]){
                sort(nums.begin()+i+1,nums.end());
                idx=i;
                break;
            }
            i-=1;
        }
        if(idx==-1){
            sort(nums.begin(),nums.end());
        }
        else{
           int j=idx+1;
           while(j<n){
               if(nums[j]>nums[idx]){
                   swap(nums[j],nums[idx]);
                   break;
               }
               j+=1;
           }
        }
    }
};