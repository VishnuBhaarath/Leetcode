class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {        
         vector<string> ans;
         for(int i=0;i<queries.size();i++){
             string st=queries[i];
             for(int j=0;j<dictionary.size();j++){
                 string st1=dictionary[j];
                 int cnt=0;
                 for(int k=0;k<st1.size();k++){
                     if(st1[k]!=st[k]){
                         cnt+=1;
                     }
                     if(cnt>2){
                        break;
                     }
                 }
                 if(cnt<=2){
                    ans.push_back(st);
                    break;
                 }
             }
         }
        return ans;
    }
};