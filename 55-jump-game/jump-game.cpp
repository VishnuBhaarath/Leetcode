class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps=nums[0];
        int j=0;
        int n=nums.size();
        if(n==1){
            return true;
        }


        while(j<n){
            int temp=j+nums[j];
            steps=max(temp,steps);
          
            if(steps>=nums.size()-1){
                return true;
            }
          
            j+=1;
            if(steps<j){
                return false;
            }
        }
        return false;
    }
};