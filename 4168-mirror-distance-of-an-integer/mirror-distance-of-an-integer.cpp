class Solution {
public:
    int mirrorDistance(int n) {
        string st=to_string(n);
        reverse(st.begin(),st.end());
        int m=stoi(st);
        return abs(n-m);
        cout<<st;
        return 27;
    }
};