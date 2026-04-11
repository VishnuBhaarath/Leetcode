class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]].push_back(i);
        }
        int ans=-1;

        for(auto x:umap){
             vector<int> v=x.second;
             if(v.size()>=3){
                 int i=0;
                 for(int j=i+1;j<v.size()-1;j++){
                      int x=v[i];
                      int y=v[j];
                      int z=v[j+1];
                      i+=1;
                      int dist=abs(y-x)+abs(z-y)+abs(x-z);
                      if(ans==-1){
                        ans=dist;
                      }
                      else{
                        ans=min(ans,dist);
                      }

                 }
             }
        }
        return ans;
    }
};