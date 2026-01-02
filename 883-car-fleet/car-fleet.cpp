class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> adj;
        int n=position.size();
        for(int i=0;i<position.size();i++){
            adj.push_back({position[i],speed[i]});
        }
        sort(adj.begin(),adj.end());
        vector<float> v(n,0);
        for(int i=n-1;i>=0;i--){
            float t1= (float)(float(target-adj[i][0])/(float)adj[i][1]);
            v[i]=t1;
            
        }
       

        stack<float> st;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(v[i]);
            }
            else if(st.top()< v[i]){
                cout<<st.top();
                st.pop();
                cnt+=1;
                st.push(v[i]);
            }
           
           
        }
      
        cnt+=st.size();
       

        return cnt;
       
    }
};