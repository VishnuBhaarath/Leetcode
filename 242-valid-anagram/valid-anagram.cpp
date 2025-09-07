class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> umap;
        vector<int>  v(26,0);
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<t.size();i++){
           
            v[t[i]-'a']+=1;
        }
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']==0){
                return false;
            }
            v[s[i]-'a']-=1;
        }
        return true;
    }
};