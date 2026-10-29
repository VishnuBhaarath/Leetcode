class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<vector<int>> v1;
        for(int i=0;i<position.size();i++){
            v1.push_back({position[i],speed[i]});
        }
        sort(v1.begin(),v1.end());
        vector<pair<int,int>> v;
        int idx=0;
       // int temp=v[0][1];
        for(int i=1;i<v1.size();i++){
             if(v1[i][0]-v1[idx][0] <=distance){
                 idx=i;
                // temp=min(temp,v[i][1]);
             }
             else{
                v.push_back({v1[idx][0],v1[idx][1]});
                idx=i;
             }
        }
        v.push_back({v1[idx][0],v1[idx][1]});

      

        stack<pair<int,int>> st;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({v[i].first,v[i].second});
            }
            else if(v[i].second<=st.top().second){
                st.push({v[i].first,v[i].second});
            }
            else{
               
            }
        }



        return st.size();
    }
};