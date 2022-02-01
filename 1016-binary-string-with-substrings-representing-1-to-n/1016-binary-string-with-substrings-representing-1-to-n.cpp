class Solution {
public:
    bool queryString(string s, int n) {
        while(n>0){
            auto S=bitset<32>(n).to_string();
         
            if(s.find((S.substr(S.find("1"))))==string::npos){
                return false;
            }
            n--;
        }
       
        return true;
    }
};