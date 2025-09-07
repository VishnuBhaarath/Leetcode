class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> umap;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<t.size();i++){
            umap[t[i]]+=1;
        }
        for(int i=0;i<s.size();i++){
            if(umap[s[i]]==0){
                return false;
            }
            umap[s[i]]-=1;
        }
        return true;
    }
};