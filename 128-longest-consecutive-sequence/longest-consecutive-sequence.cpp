class Solution {
public:
    vector<long long int> parent; unordered_map<long long int, long long int> umap;
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==0){
            return 0;
        }
        parent.resize(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] =i;
            parent[i] = nums[i];
        }
        long long int ans = 1;

        for (int i = 0; i < nums.size(); i++) {
          
            if(umap.find(nums[i]-1)!=umap.end()){
                int idx=umap[nums[i]-1];
                if(parent[idx]== nums[i]-1){
                   find(i,nums);}
                   else{
                    parent[i]=parent[idx];
                   }
            }
           
        }
       // long long int ans=1;
        for(int i=0;i<parent.size();i++){
          
            long long int val=nums[i]-parent[i]+1;
            ans=max(ans,val);
         
        }
    

        return ans;
    }
    int find(int x,vector<int>&nums) { 
        if(umap.find(nums[x]-1)==umap.end()){
            return parent[x]=nums[x];
        }
        return parent[x] = find(umap[nums[x]-1],nums);
         
    }
};