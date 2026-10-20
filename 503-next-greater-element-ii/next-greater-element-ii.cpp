class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        vector<int> ans(n,-1);
        v=nums;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        stack<int> s;
        for(int i=0;i<v.size();i++){
            if(s.empty()){
                s.push(i);
            }
            else if(v[i]<=v[s.top()]){
                s.push(i);
            }
            else{
                 while(v[i]>v[s.top()]){
                    if(s.top()<n){
                        ans[s.top()]=v[i];
                    }
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                 }
                 s.push(i);
            }
        }
        return ans;
    }
};