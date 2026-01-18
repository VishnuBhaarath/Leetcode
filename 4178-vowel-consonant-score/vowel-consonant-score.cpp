class Solution {
public:
    int vowelConsonantScore(string s) {
        int s1=0;
        int s2=0;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
             s1+=1;
            }
            else{
                s2+=1;
            }
        }}
        if(s2==0){
            return 0;
        }
    return floor(s1/s2);
    }
};