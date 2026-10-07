class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0;
        map<int,int> umap;
        umap[0]+=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                sum+=1;
            }
            cnt+=umap[sum-k];
            umap[sum]+=1;
        }
        return cnt;
    }
};