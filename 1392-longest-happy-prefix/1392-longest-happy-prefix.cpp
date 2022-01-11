class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> v(n,0);
        int i=0;
        int j=1;
        while(j<n){
          if(s[i]==s[j]){
              v[j]=i+1;
              j+=1;
              i+=1;
          }
            else{
                if(i!=0){
                    i=v[i-1];
                }
                else{
                    j+=1;
                }
            }
            
        }
        string ans=s.substr(n-v[n-1],v[n-1]);
        return ans;
    }
};