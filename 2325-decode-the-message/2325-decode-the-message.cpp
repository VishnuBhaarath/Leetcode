class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,char> umap;
        map<char,int> umap1;
        char ch='a';
        for(int i=0;i<key.size();i++){
            if(isalpha(key[i])){
            if(umap1[key[i]]==0){
                umap1[key[i]]+=1;
                umap[key[i]]=ch;
                ch+=1;
            }}
     
            }
   
        string ans="";
        for(int i=0;i<message.size();i++){
            if(isalpha(message[i])){
            ans+=umap[message[i]];}
                else{
                    ans+=" ";
                }
        
        }
        
       
        return ans;
    }
};