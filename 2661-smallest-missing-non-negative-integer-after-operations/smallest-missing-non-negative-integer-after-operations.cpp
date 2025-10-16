class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> umap;
     

        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[i])%value;
            if(nums[i]<0){
                nums[i]+=value;
            }
            umap[nums[i]]+=1;
            int cnt=umap[nums[i]];
            if(cnt>1){
                int val=nums[i]+(cnt-1)*value;
                umap[val]+=1;
            }
        }
        int i=0;
      
        while(1){
            if(umap[i]==0){
                return i;
            }
            i+=1;
        }
        return 0;
    }
};