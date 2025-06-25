class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]==val){
                while(nums[j]==val){
                    j-=1;
                    if(j<=i){
                        return i;
                    }
                }
                nums[i]=nums[j];
                j-=1;
               
            }
             i+=1;
        }
        return i;
    }
};