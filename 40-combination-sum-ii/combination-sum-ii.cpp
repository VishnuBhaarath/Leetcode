class Solution {
public:
 vector<vector<int>> dp;
set<vector<int>> s;
    void func(vector<int>& candidates, int target,int sum,vector<int> &v,int i){
      
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
           func(candidates,target,sum+candidates[i],v,i+1);
           v.pop_back();
           int j=i+1;
           while(j<candidates.size() && candidates[j]==candidates[i]){
            j+=1;
           }
           func(candidates,target,sum,v,j);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        func(candidates,target,0,v,0);

        return dp;
    }
};