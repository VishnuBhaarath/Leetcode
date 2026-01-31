class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int,int> umap;
        for(int i=0;i<intervals.size();i++){
            umap[intervals[i][0]]+=1;
            umap[intervals[i][1]]-=1;
        }
      umap[newInterval[0]]+=1;
umap[newInterval[1]]-=1;
        vector<vector<int>> ans;
        vector<int> v;
        int cnt=0;
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