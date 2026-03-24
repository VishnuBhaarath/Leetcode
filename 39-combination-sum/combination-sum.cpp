class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    void func(vector<int>& candidates,vector<int>& v, int i, int target,int sum){
        
        if(sum>target){
            return;
        }
        if(sum==target){
             
                ans.push_back(v);
             
             return;
        }
        if(i==candidates.size()){
            return;
        }
        v.push_back(candidates[i]);
        func(candidates,v,i,target,sum+candidates[i]);
        v.pop_back();
        func(candidates,v,i+1,target,sum);
         
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        func(candidates,v,0,target,0);
        return ans;
        
    }
};