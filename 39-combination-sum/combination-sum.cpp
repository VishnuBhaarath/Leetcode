class Solution {
public:
    vector<vector<int>> dp;
    void func(vector<int>& candidates, int target,int sum,vector<int> v,int i){
      
        if(sum==target){
            dp.push_back(v);
            return;
        }
        if(i==candidates.size()){
            return;
        }
        if(sum>target){
            return;
        }
           v.push_back(candidates[i]);
           func(candidates,target,sum+candidates[i],v,i);
           v.pop_back();
           func(candidates,target,sum,v,i+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        func(candidates,target,0,{},0);

        return dp;
        
    }
};