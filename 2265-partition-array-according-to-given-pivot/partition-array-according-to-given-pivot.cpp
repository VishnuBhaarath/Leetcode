class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> v(n,0);
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                v[idx]=nums[i];
                idx+=1;
            }
            
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot){
                v[idx]=nums[i];
                 idx+=1;
            }
           
        }

          for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                v[idx]=nums[i];
                 idx+=1;
            }
           
        }
return v;
    }
};