class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s,s1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else {
                if(nums[i]<nums[s.top()]){
                    s.push(i);
                }
                else{
                    s1.push(i);
                }
            }
        }
       
        while(!s.empty() && !s1.empty()){
            int tp=s1.top();
            while(tp<s.top()){
                s.pop();
            }
            while(tp>s.top() && nums[tp]>=nums[s.top()]){
                int sz=tp-s.top();
                ans=max(ans,sz);
                s.pop();
                if(s.empty()){
                    break;
                }
            }
            if(!s.empty()){
                if(tp<s.top() || nums[tp]<nums[s.top()]){
                    s1.pop();
                }
            }
        }


        return ans;
    }
};