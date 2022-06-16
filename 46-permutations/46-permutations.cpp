class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>,int>umap1;
    vector<vector<int>> permute(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            map<int,int> umap;
            umap[nums[i]]+=1;
            vector<int> v;
            v.push_back(nums[i]);
            backtrack(umap,v,nums,i);
           
        }
         return ans;
    }
    void backtrack(map<int,int> umap,vector<int> v,vector<int> nums,int i){
       
         
        if(v.size()==nums.size()){
            if(umap1[v]==0){
            ans.push_back(v);
            umap1[v]+=1;}
            return;
        }
  
        for(int j=0;j<nums.size();j++){
            if(umap[nums[j]]==0){
                v.push_back(nums[j]);
                umap[nums[j]]=1;
                backtrack(umap,v,nums,j);
               
                umap[nums[j]]=0;
             
                v.pop_back();
            }
        }
       
    }
};