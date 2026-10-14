class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> v(n+1,0);
        
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        for(int i=0;i<n;i++){
            pq1.push(i);
        }
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<meetings.size();i++){
            if(!pq.empty()){
                 while(pq.top().first<=meetings[i][0]){
                     pq1.push(pq.top().second);
                     pq.pop();
                     if(pq.empty()){
                        break;
                     }
                 }
            }
            if(pq1.empty()){
                long long st=pq.top().first;
                int idx=pq.top().second;
                pq.pop();
                v[idx]+=1;
                pq.push({st+(meetings[i][1]-meetings[i][0]),idx});
            }
            else{
                int idx=pq1.top();
                v[idx]+=1;
                pq.push({meetings[i][1],idx});
                pq1.pop();
            }
        }

        int ans = 0;
        int idx = -1;
        for(int i = 0; i < v.size(); i++){
            if(v[i] > ans){
                ans = v[i];
                idx = i;
            }
        }
        return idx;
    }
};