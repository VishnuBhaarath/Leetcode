class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> umap;
       
        for(int i=0;i<s.size();i++){
           if(umap[s[i]]!=0){
             if(umap[s[i]]!=t[i]){
                return false;
             }
           }
           umap[s[i]]=t[i];
        }
        map<char,char> umap1;

        for(int i=0;i<t.size();i++){
           if(umap1[t[i]]!=0){
             if(umap1[t[i]]!=s[i]){
                return false;
             }
           }
           umap1[t[i]]=s[i];
        }
        return true;
    }
};