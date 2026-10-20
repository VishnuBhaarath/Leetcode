class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        vector<int> ans(n,-1);
        v=nums;
       
        stack<int> s;
        for(int i=0;i<(2*n);i++){
            int j=i%n;
            if(s.empty()){
                s.push(j);
            }
            else if(v[j]<=v[s.top()]){
                s.push(j);
            }
            else{
                 while(v[j]>v[s.top()]){
                    if(s.top()<n){
                        ans[s.top()]=v[j];
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