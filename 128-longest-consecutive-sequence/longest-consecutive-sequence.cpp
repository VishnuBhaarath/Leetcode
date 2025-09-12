class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        int ans=0;
        map<int,int> umap1;
        for(int i=0;i<nums.size();i++){
            if(umap[nums[i]-1]==0 && umap1[nums[i]]==0){
                int cnt=1;
                umap1[nums[i]]+=1;
                int j=nums[i]+1;
                while(umap[j]>0){
                    cnt+=1;
                    j+=1;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};