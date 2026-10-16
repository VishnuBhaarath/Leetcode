class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> umap;
        int odd=0;
        int even=0;
        int ans=0;
       
        umap[0]+=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                cnt+=1;
            }
            ans+=umap[cnt-k];
            umap[cnt]+=1;

        }
        return ans;
    }
};