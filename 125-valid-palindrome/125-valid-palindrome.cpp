class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                char a=tolower(s[i]);
                
                temp+=a;
            }
        
        }
        string temp1=temp;
        reverse(temp.begin(),temp.end());
        if(temp1==temp){
            return true;
        }
        return false;
    }
};