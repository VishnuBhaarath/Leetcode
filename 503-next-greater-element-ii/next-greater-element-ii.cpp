class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            if(s.empty()){
                s.push(i);
            }
            else if(nums[i]==nums[s.top()]){
                s.push(i);
            }
            else{
                while(nums[i]>=nums[s.top()]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }

                }
                s.push(i);
            }

        }
       
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
                ans[i]=-1;
            }
            else if(nums[i]<nums[s.top()]){
                ans[i]=nums[s.top()];
                s.push(i);
            }
            else{
                 while(nums[i]>=nums[s.top()]){
                    s.pop();
                    if(s.empty()){
                      break;
                    }
                 }
                 if(s.empty()){
                    ans[i]=-1;
                 }
                 else{
                    ans[i]=nums[s.top()];
                 }
                 s.push(i);
            }
        }
        return ans;
    }
};