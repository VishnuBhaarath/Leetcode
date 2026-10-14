class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> v(k+1,0);
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> s;

        int ans=0;
        for(int i=0;i<k;i++){
            s.insert(i);
        }

        for(int i=0;i<arrival.size();i++){
            if(!pq.empty()){
                while(pq.top().first<=arrival[i]){
                    s.insert(pq.top().second);
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
                }
            }

            if(s.empty()) continue;          // all servers busy, drop the request

            auto it = s.lower_bound(i % k); 
            if (it == s.end())
                it = s.begin(); 
            int server = *it;
            s.erase(it); 
            v[server]+=1;
            ans=max(ans,v[server]);

            pq.push({arrival[i]+load[i], server});   // server is busy until this time
        }
        vector<int> v1;
        for(int i=0;i<v.size();i++){
           if(v[i]==ans){
            v1.push_back(i);
           }
        }
       
        return v1;
    }
};