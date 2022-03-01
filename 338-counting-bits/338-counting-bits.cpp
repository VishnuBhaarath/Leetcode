class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        v.push_back(0);
        if(n==0){
            return v;
        }
        v.push_back(1);
        if(n==1){
            return v;
        }
        v.push_back(1);
        if(n==2){
            return v;
        }
        v.push_back(2);
        if(n==3){
            return v;
        }
        v.push_back(1);
        if(n==4){
            return v;
        }
        int prev=4;
        for(int i=5;i<=n;i++){
            int val=log2(i);
            if(val==log2(i)){
                v.push_back(1);
                prev=i;
            }
            else{
            v.push_back(1+v[i-prev]);}
        }
        return v;
    }
};