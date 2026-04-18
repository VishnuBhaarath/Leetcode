class Solution {
public:
    int mirrorDistance(int n) {
        int m=n;
        while(n%10==0){
            n=n/10;
        }
      
        string st=to_string(n);
        reverse(st.begin(),st.end());
        int val=stoi(st);

        return abs(m-val);
    }

};