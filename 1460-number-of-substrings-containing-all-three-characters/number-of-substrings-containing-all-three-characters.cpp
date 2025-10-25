class Solution {
public:
    int numberOfSubstrings(string s) {
        
         vector<int> m(3,0);
        int i=0,j=0,n=s.size(),ans=0;
        while(j<n){
            m[s[j]-'a']++;
            while(m[0] && m[1] && m[2]){
                ans+=n-j;
                m[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};