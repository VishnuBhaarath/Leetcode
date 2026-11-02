class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
             int idx=i;
             if(umap[idx]==0){
                 int temp=nums[idx];
                 umap[idx]+=1;
                 while(1){
                    int idx1=(idx+k)%n;
                    
                    int prev=nums[idx1];
                    nums[idx1]=temp;
                    temp=prev;
                    idx=idx1;
                    if(idx1==i){
                        break;
                    }
                    umap[idx]+=1;
                 }

             }
        }
    }
};