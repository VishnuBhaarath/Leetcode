class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]=0;
            }
        }
       
        for(int i=0;i<nums.size();i++){
             int val=nums[i];
           
             if(abs(val)<=nums.size() && val!=0){
                if(nums[abs(val)-1]>0){
                nums[abs(val)-1]= -nums[abs(val)-1];
                }
                else if(nums[abs(val)-1]==0){
                    nums[abs(val)-1]=-1e6;
                }
             }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                return i+1;
            }
            cout<<nums[i];
            cout<<" ";
        }
        return nums.size()+1;
    }
};