class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<vector<double>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({(double)(position[i]),(double)(speed[i])});
        }
        sort(v.begin(),v.end());
        vector<double> v1;
        for(int i=0;i<v.size();i++){
          
double t = ((double)target - (double)v[i][0])
           / (double)v[i][1];
           
            v1.push_back(t);
        }

       

        stack<double> st;
        for(int i=0;i<v1.size();i++){
            if(st.empty()){
                st.push(v1[i]);
            }
            else{
                if(v1[i]<st.top()){
                    st.push(v1[i]);
                }
                else{
                    while(v1[i]>=st.top()){
                        st.pop();
                        if(st.empty()){
                            break;
                        }
                    }
                    st.push(v1[i]);
                }
            }
        }
       
        return st.size();
    }
};