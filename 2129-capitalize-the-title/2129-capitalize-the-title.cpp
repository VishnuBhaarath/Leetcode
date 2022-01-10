class Solution {
public:
    string capitalizeTitle(string title) {
        string ans="";
        string word="";
        for(int i=0;i<title.size();i++){
            if(title[i]==' '){
                if(word.size()>2){
                    word[0]=toupper(word[0]);
                    ans+=word;
                 
                    
                }
                else{
                    ans+=word;
                }
                word="";
                ans+=' ';
            }
            else{
               
                word+=tolower(title[i]);
            }
        }
        if(word.size()>2){
        word[0]=toupper(word[0]);}
        ans+=word;
        return ans;
    }
};