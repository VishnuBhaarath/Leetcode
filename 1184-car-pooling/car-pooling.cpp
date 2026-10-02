class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> v(1001,0);
        for(int i=0;i<trips.size();i++){
            v[trips[i][1]]+=trips[i][0];
            v[trips[i][2]]-=trips[i][0];
        }
        int cnt=0;
        for(int i=0;i<v.size();i++){
            cnt+=v[i];
            if(cnt>capacity){
                return false;
            }
        }
        return true;
    }
};