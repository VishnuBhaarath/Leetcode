class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> umap;
        int i=0;
        int j=0;
        int n=s.size();
        int cnt=0;
        while(j<s.size()){
            umap[s[j]]+=1;
            while(umap['a']>0 && umap['b']>0 && umap['c']>0){
                cnt+=(n-j);
                umap[s[i]]-=1;
                i+=1;
            }
          
            j+=1;
        }
        return cnt;
    }
};