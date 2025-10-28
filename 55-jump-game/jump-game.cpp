class Solution {
public:
    bool canJump(vector<int>& nums) {
        int val=nums[0];
        
         int n=nums.size();
          if(val>=(n-1)){
                    return true;
                }
        for(int i=1;i<nums.size();i++){
            if(i >val){
                return false;
            }
            else{
                val=max(val,i+nums[i]);
                if(val>=(n-1)){
                    return true;
                }

            }
        }
        return false;
    }
};