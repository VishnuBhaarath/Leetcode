class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans = INT_MAX;

        vector<vector<int>> v;
        map<int,int> umap;
        for (int j = 0; j < n / 2; j++) {
            int val1 = nums[j];
            int val2 = nums[n - 1 - j];
            int temp1 = min(val1, val2);
            int temp2 = max(val1, val2);
            int l=temp1+1;
            int r=temp2+limit;
            umap[l]-=1;
            umap[r+1]+=1;
            umap[val1+val2]-=1;
            umap[val1+val2+1]+=1;
           
        }
        int cnt=n;
      //  sort(v.begin(),v.end());
      
        for(auto x:umap){
        
            cnt+=x.second;
            ans=min(ans,cnt);
        }

        return ans;
    }
};