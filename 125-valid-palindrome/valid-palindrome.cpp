class Solution {
public:
    bool isPalindrome(string s) {
        string st;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                st+=tolower(s[i]);
            }
        }
        int n=st.size();
        int i=0;
        int j=n-1;

        while(i<=j){
            if(st[i]!=st[j]){
                return false;
            }
            i+=1;
            j-=1;
        }
    
        return true;
    }
};