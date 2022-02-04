class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       
        int n=nums.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
          int prev=nums[idx+1];
            int idx1=idx+1;
          for(int i=idx+1;i<n;i++){
              if(nums[i]>nums[idx]){
                  if(nums[i]<=prev){
                      prev=nums[i];
                      idx1=i;
                  }
                
              }
             
          }  
            swap(nums[idx],nums[idx1]);
            
            reverse(nums.begin()+idx+1,nums.end());
        }
    }
};