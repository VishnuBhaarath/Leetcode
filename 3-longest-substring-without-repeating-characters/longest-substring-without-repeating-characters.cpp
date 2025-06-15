class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> umap;
        int j=0;
        int i=0;
        int len=0;
        for(int j=0;j<s.size();j++){
           umap[s[j]]+=1;
           while(umap[s[j]]>1){
               umap[s[i]]-=1;
               i+=1;
           }
          len=max(len,(j-i+1));
        
        }

        return len;
    }
};