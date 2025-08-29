class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
        string word=strs[0];
        int j=1;
        while(j<strs.size()){
            string word1=strs[j];
            int k=0;
            string s1="";
            while(k<min(word.size(),word1.size())){
                if(word[k]==word1[k]){
                     s1+=word[k];
                }
                else{
                    break;
                }
              k+=1;
                
            }
            word=s1;
            j+=1;
        }
        return word;
    }
};