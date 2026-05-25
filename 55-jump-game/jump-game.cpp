class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int r=nums[0];
        int n=nums.size();
        if(n==1){
            return true;
        }

        int i=1;
        while(i<=r){
            int idx=i+nums[i];
if(idx>=(n-1)){
    return true;
}
r=max(r,idx);
            
            i+=1;
        }

        return false;
    }
};