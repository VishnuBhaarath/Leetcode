class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<pair<int,int>,int> umap;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if((abs(nums[i]-nums[j]))==k){
                    
                    pair<int,int> p={nums[i],nums[j]};
                    if(nums[j]<nums[i]){
                        p={nums[j],nums[i]};
                    }
                    if(umap[p]==0){
                        
                        cnt+=1;
                        umap[p]+=1;
                    }
                }
            }
        }
        return cnt;
    }
};