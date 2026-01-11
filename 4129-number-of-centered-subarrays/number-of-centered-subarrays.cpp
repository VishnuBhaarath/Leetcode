class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            sum+=nums[i];
            map<int,int> umap;
            umap[nums[i]]+=1;
            for(int j=i+1;j<nums.size();j++){
                umap[nums[j]]+=1;
                sum+=nums[j];
                if(umap[sum]!=0){
                  cnt+=1;
                }
            }
        }
        cnt+=nums.size();
        return cnt;
    }
};