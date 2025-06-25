class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            int idx=i;
            int j=0;
            while(haystack[idx]==needle[j]){
                idx+=1;
                j+=1;
                if(needle.size()==j){
                    return i;
                }
                 if(haystack.size()==idx){
                    return -1;
                 }
            }
        }
        return -1;
    }
};