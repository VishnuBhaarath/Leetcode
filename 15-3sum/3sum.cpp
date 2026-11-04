class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            int j=i+1;
            int k=n-1;
            map<pair<int,int>,int> umap;
            while(j<k){
                 if(nums[i]+nums[j]+nums[k]==0){
                     if(umap[{nums[j],nums[k]}]==0){
                         ans.push_back({nums[i],nums[j],nums[k]});
                         umap[{nums[j],nums[k]}]=1;
                     }
                     j+=1;
                     k-=1;
                 }
                 else if(nums[i]+nums[j]+nums[k]>0){
                    k-=1;
                 }
                 else{
                    j+=1;
                 }
            }
           j=i+1;
           if(i+1 >=n){
            break;
           }
            while(nums[j]==nums[i]){
                j+=1;
                if(j>=n){
                    i=j;
                    break;
                }
            }
            i=j;
        }
        return ans;
    }
};