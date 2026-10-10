class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        stations.push_back({target,0});
        sort(stations.begin(),stations.end());
        int cnt=0;
        int st=0;
        for(int i=0;i<stations.size();i++){
             int dist=stations[i][0]-st;
             if(dist<=startFuel){
                startFuel-=dist;
                st=stations[i][0];
                pq.push(stations[i][1]);
             }
             else{
                 if(pq.empty()){
                    return -1;
                 }
                 int t=0;
                 while(!pq.empty()){
                    startFuel+=pq.top();
                    pq.pop();
                    cnt+=1;
                    if(startFuel>=dist){
                        startFuel-=dist;
                        pq.push(stations[i][1]);
                        st=stations[i][0];
                        t=1;
                        break;
                    }
                 }
                 if(t==0){
                    return -1;
                 }
             }
            
        }
        return cnt;
    }
};