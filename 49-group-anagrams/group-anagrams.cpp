class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for(int i=0;i<strs.size();i++){
            string st=strs[i];
            sort(st.begin(),st.end());
            umap[st].push_back(strs[i]);
        }
        vector<vector<string>> v;
        for(auto x: umap){
            vector<string> v1=x.second;
            
            v.push_back(v1);
         
        }

        

        return v;
    }
};