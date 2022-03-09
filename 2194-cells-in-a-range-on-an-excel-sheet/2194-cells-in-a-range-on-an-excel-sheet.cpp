class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        int l=s[1]-'0';
        int r=s[4]-'0';
        char st=s[0];
        char end=s[3];
        for(char i=st;i<=end;i++){
            
            for(int j=l;j<=r;j++){
              string temp="";  
            cout<<i;
                temp+=i;
                temp+=to_string(j);
                ans.push_back(temp);
              
            }
            
          
        }
        return ans;
    }
};