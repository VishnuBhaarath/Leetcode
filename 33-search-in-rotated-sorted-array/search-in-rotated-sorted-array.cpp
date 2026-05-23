class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
       if(target==nums[n-1]){
        return n-1;
       }
       if(target==nums[0]){
        return 0;
       }
        while(l<=r){
            int m=l+(r-l)/2;
          
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]<=nums[0] && nums[m]<=nums[n-1]){
               
                if(target<nums[m]){
                    r=m-1;
                }
                else{
                    
                    if(target<nums[n-1]){
                        l=m+1;
                    }
                    else{
                        r=m-1;
                    }
                }
                
            }
            else if(nums[m]>=nums[0] && nums[m]>=nums[n-1]){
                
if(target>nums[m]){
      
                    l=m+1;
                }
                else{
                    if(target>nums[0]){
                        r=m-1;
                    }
                    else{
                        l=m+1;
                    }
                }
            }
            else if(nums[m]>=nums[0] && nums[m]<=nums[n-1]){
                if(target>nums[m]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
               
            }
          
        }
        return -1;
    }
};