class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> umap;
        int i=0;
        int j=1;
        if(s.size()==0){
            return 0;
        }
        int ans=1;
        int cnt=1;
        umap[s[0]]+=1;
        while(j<s.size()){
        
           if(umap[s[j]]==0){
              umap[s[j]]+=1;
              cnt+=1;
              ans=max(ans,cnt);
              j+=1;
           }
           else{
              while(i<j){
                umap[s[i]]-=1;
                i+=1;
                if(umap[s[j]]==0){
                    umap[s[j]]+=1;
                    cnt=(j-i)+1;
                    ans=max(ans,cnt);
                    j+=1;
                    break;
                }
                if(i==j){
                    return ans;
                }
              
            }
           }
        
        }
        return ans;
    }
};