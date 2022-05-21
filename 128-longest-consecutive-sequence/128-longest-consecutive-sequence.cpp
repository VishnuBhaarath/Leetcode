class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        int t=0;
        int prev=0;
        int val=0;
        int ans=1;
        for(auto x:umap){
            if(t==0){
                prev=x.first;
                val=1;
                t=1;
            }
            else{
                if((prev+1)==x.first){
                    val+=1;
                    prev+=1;
                }
                else{
                    ans=max(ans,val);
                    prev=x.first;
                    val=1;
                }
            }
        }
        ans=max(ans,val);
        return ans;
    }
};