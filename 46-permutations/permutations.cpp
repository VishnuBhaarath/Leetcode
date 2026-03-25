class Solution {
public:
 vector<vector<int>> ans;
    void func(vector<int>& nums,vector<int> &v,int i,vector<int> &visited){
         
         
         if(v.size()==nums.size()){
            
         ans.push_back(v);
            return;
         }
      
         
      
        for(int j=0;j<nums.size();j++){
            if(visited[j]==0){
                 visited[j]=1;
                 v.push_back(nums[j]);
                 func(nums,v,i,visited);
                 visited[j]=0;
                 v.pop_back();
               
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        vector<int> visited(n,0);
        func(nums,v,0,visited);
       
        return ans;
    }
};