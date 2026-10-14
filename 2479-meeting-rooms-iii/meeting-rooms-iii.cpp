class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
         vector<int> v(n, 0);

        // (time room becomes free, room index); long long to avoid overflow
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        for(int i = 0; i < n; i++){
            pq.push({0, i});
        }
        sort(meetings.begin(), meetings.end());

        for(int i = 0; i < meetings.size(); i++){

            queue<pair<long long,int>> q;
            int t = -1;
            while(pq.top().first <= meetings[i][0]){
                q.push({pq.top().first, pq.top().second});
                if(t == -1){
                    t = pq.top().second;
                }
                else{
                    t = min(t, pq.top().second);
                }
                pq.pop();
                if(pq.empty()){
                    break;
                }
            }
            if(t != -1){
                v[t] += 1;
            }
            while(!q.empty()){
                if(q.front().second != t){
                    pq.push({q.front().first, q.front().second});
                }
                else{
                    // room is free, so the meeting starts on time and ends at meetings[i][1]
                    pq.push({meetings[i][1], q.front().second});
                }
                q.pop();
            }
            if(t == -1){
                long long tp = pq.top().first;
                int idx = pq.top().second;
                pq.pop();
                v[idx] += 1;
                // delayed meeting keeps its duration
                pq.push({tp + (meetings[i][1] - meetings[i][0]), idx});
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