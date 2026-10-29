class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        int n=v.size();
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({v[i].first,v[i].second});
            }
            else if(v[i].second<=st.top().second){
                st.push({v[i].first,v[i].second});
            }
            else{
                double t1= double(target-st.top().first)/ (double)(st.top().second);
                double t2=(double)(target-v[i].first)/(double)(v[i].second);
                
               
               

                if(t1<t2){
                    st.push({v[i].first,v[i].second});
                }

            }
        }

        return st.size();
    }
};