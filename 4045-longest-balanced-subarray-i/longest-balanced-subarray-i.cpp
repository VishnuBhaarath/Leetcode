class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> umap;
            int cnt1=0;
            int cnt2=0;
            for(int j=i;j<nums.size();j++){
                  if(umap[nums[j]]==0){
                      if(nums[j]%2 ==0){
                         cnt1+=1;
                      }
                      else{
                       cnt2+=1;
                      }
                  }
                  umap[nums[j]]+=1;
                  if(cnt1==cnt2){
                     ans=max(ans,j-i+1);
                  }
            }
        }
        return ans;
    }
};