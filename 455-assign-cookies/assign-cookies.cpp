class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size();
        int m=s.size();
        int i=0;
        int cnt=0;
        int j=0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                cnt+=1;
                i+=1;
                j+=1;
            }
            else{
                j+=1;
            }
        }
        return cnt;
    }
};