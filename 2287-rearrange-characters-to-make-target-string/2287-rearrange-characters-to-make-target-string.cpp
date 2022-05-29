class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> umap;
        for(int i=0;i<s.size();i++){
            umap[s[i]]+=1;
        }
        int cnt=-1;
        map<char,int> umap1;
        for(int i=0;i<target.size();i++){
            umap1[target[i]]+=1;
        }
       for(auto x:umap1){
           int val=umap[x.first];
           int q=val/x.second;
           if(cnt==-1){
               cnt=q;
           }
           else{
               cnt=min(cnt,q);
           }
       }
        return cnt;
    }
};