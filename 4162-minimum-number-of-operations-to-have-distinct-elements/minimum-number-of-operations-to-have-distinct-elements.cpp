class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> umap;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
            if(umap[nums[i]]==2){
                cnt+=1;
            }
        }
        
     
        if(cnt==0){
            return 0;
        }
        int ops=1;
        int t=0;
        for(int i=0;i<nums.size();i++){
             if(umap[nums[i]]==2){
              //  umap[nums[i]]-=1;
                cnt-=1;
             }
           
             umap[nums[i]]-=1;
             if(cnt==0){
                return ops;
             }
              t+=1;
              if(t==3){
                ops+=1;
                t=0;
              }
        }
return ops;
    }
};