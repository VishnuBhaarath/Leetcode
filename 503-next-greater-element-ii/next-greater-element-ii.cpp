class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       
        int n=nums.size();
        vector<int> ans(n,-1);
      
       
        stack<int> s;
        for(int i=0;i<(2*n);i++){
            int j=i%n;
            if(s.empty()){
                s.push(j);
            }
            else if(nums[j]<=nums[s.top()]){
                s.push(j);
            }
            else{
                 while(nums[j]>nums[s.top()]){
                    if(s.top()<n){
                        ans[s.top()]=nums[j];
                    }
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                 }
                 s.push(j);
            }
        }
        return ans;
    }
};