class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> v(right+1,0);
        for(int i=0;i<ranges.size();i++){
            int l=ranges[i][0];
            int r=ranges[i][1]+1;
            if(l<v.size()){
                v[l]+=1;
            }
            if(r<v.size()){
                v[r]-=1;
            }
        }
        int cnt=0;
       
        for(int i=0;i<=right;i++){
            cnt+=v[i];
            if(i>=left){
            if(cnt<=0){
                return false;
            }}
        }
        return true;
    }
};