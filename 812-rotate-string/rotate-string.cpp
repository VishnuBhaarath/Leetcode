class Solution {
public:
    bool rotateString(string s, string goal) {
        string s1=s+s;
        int n=s.size();
        for(int i=0;i<n;i++){
            string s2=s1.substr(i,n);
        
            if(s2==goal){
                return true;
            }
           
        }
        return false;
    }
};