class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> umap;
        for(int i=0;i<strs.size();i++){
            string s1=strs[i];
            sort(s1.begin(),s1.end());
            umap[s1].push_back(strs[i]);
        }
            vector<vector<string>> ans;
        for(auto x:umap){
             ans.push_back(x.second);
        }
    
        return ans;
    }
};