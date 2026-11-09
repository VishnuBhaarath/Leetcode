class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        int cnt=0;
        int ans=0;
        int prev=-1;
        int t=-1;
        for(auto x:umap){
             if(t==-1){
                prev=x.first;
                cnt=1;
                ans=max(ans,cnt);
                t=0;
             }
             else{
                if(prev+1==x.first){
                    cnt+=1;
                    prev=x.first;
                    ans=max(ans,cnt);
                }
                else{
                    ans=max(ans,cnt);
                    prev=x.first;
                    cnt=1;
                }
             }
        }

        return ans;
    }
};