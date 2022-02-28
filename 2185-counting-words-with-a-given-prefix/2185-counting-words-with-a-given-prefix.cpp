class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            if(temp.substr(0,pref.size())==pref){
                cnt+=1;
            }
        }
        return cnt;
    }
};