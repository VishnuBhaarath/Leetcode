class Solution {
public:
    int residuePrefixes(string s) {
        int ans=0;
        int i=0;
            map<char,int> umap;
            int cnt=0;
            for(int j=i;j<s.size();j++){
               if(umap[s[j]]==0){
                umap[s[j]]+=1;
                cnt+=1;
               }
               int sz=j-i+1;
               int val=sz%3;
               if(val==cnt){
                ans+=1;
               }
            }
        
        return ans;
    }
};