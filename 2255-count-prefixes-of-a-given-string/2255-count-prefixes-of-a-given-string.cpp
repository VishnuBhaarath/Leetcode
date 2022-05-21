class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string st=words[i];
            if(st.size()<=s.size()){
                if(s.substr(0,st.size())==st){
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};