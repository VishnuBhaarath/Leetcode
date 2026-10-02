class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> v;
        vector<vector<int>> r;
        for(int i=0;i<logs.size();i++){
            v.push_back({logs[i][0],1});
            v.push_back({logs[i][1],-1});
        }
        sort(v.begin(),v.end());
        int ans=0;
        int cnt=0;
        int year=0;
        for(int i=0;i<v.size();i++){
             if(v[i][1]==1){
                cnt+=1;
             }
             else{
                cnt-=1;
             }
             if(cnt>ans){
                ans=cnt;
                year=v[i][0];
             }
             
        }
        return year;
    }
};