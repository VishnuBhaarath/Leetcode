class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else {
                if(nums[i]<nums[s.top()]){
                    s.push(i);
                }
              
            }
        }
        int n=nums.size();
        //int ans=0;
        for(int j=n-1;j>=0;j--){
             while(nums[j]>=nums[s.top()]){
                int sz=j-s.top();
                ans=max(ans,sz);
                s.pop();
                if(s.empty()){
                    break;
                }
             }
             if(s.empty()){
                break;
             }
        }
       
        

        return ans;
    }
};