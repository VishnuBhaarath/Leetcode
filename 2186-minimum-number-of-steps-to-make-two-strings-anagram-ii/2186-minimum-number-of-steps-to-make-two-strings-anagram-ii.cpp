class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> umap1,umap2;
        for(int i=0;i<s.size();i++){
            umap1[s[i]]+=1;
        }
        for(int i=0;i<t.size();i++){
            umap2[t[i]]+=1;
        }
        int cnt=0;
        for(char i='a';i<='z';i++){
            cnt+=abs(umap1[i]-umap2[i]);
           
        }
        return cnt;
    }
};