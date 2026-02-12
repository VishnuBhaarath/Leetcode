class Solution {
public:
    int longestBalanced(string s) {
        int cnt=1;
        for(int i=0;i<s.size();i++){
              vector<int> v(26,0);
             for(int j=i;j<s.size();j++){
                 v[s[j]-'a']+=1;
                 int prev=0;
                 for(int k=0;k<26;k++){
                     if(v[k]!=0){
                         if(prev!=0){
                             if(prev!=v[k]){
                                prev=-1;
                                break;
                             }
                         }
                         else{
                            prev=v[k];
                         }
                     }
                 }
                 if(prev!=-1){
                    int sz=(j-i)+1;
                    cnt=max(cnt,sz);
                 }
             }
        }
        return cnt;
    }
};