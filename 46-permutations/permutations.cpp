class Solution {
public:
    void func(vector<int>& nums,vector<int>& visited,vector<int> &v,vector<vector<int>>&ans){
        
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                v.push_back(i);
                func(nums,visited,v,ans);
            }
        }
        int n=v.size();
        if(n>0){
        if(n==nums.size()){
            vector<int> v1;
            for(int i=0;i<n;i++){
                v1.push_back(nums[v[i]]);
            }
            ans.push_back(v1);
        }   
        int val=v[n-1];
        visited[val]=0;
        v.pop_back();}
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,0);
        vector<int> v;
         vector<vector<int>> ans;
        func(nums,visited,v,ans);
       

        return ans;
    }
};