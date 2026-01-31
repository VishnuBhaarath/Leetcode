class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> umap;
        for(int i=0;i<intervals.size();i++){
            umap[intervals[i][0]]++;
            umap[intervals[i][1]]--;
        }
        vector<vector<int>> ans;
        int cnt=0;
        vector<int> v;

        for(auto x:umap){
          if(v.size()==0){
             v.push_back(x.first);
          }
          cnt+=x.second;
          if(cnt==0){
            v.push_back(x.first);
            ans.push_back(v);
            v.clear();
          }
        }
        return ans;
    }
};