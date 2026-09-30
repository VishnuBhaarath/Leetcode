class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> umap;
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(umap[s[j]]==0){
                umap[s[j]]+=1;
                int sz=(j-i+1);
                   ans=max(ans,sz);
                j+=1;
            }
            else{
                while(umap[s[j]]!=0){
                    umap[s[i]]-=1;
                    i+=1;
                }
                umap[s[j]]+=1;
                int sz=(j-i+1);
                   ans=max(ans,sz);
                j+=1;
            }
            
         
        }
        return ans;
    }
};