class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> umap;
        if(s.size()==0){
            return 0;
        }
        int i=0;
        int j=0;
        umap[s[j]]+=1;
        j+=1;
        int ans=1;
        while(j<s.size()){
            if(umap[s[j]]==0){
                umap[s[j]]+=1;
            }
            else{
                while(s[i]!=s[j]){
                    umap[s[i]]-=1;
                    i+=1;
                }
                umap[s[i]]-=1;
                i+=1;
                umap[s[j]]+=1;
            }
            int sz=j-i+1;
            ans=max(ans,sz);
            j+=1;
        }

        return ans;

    }
};