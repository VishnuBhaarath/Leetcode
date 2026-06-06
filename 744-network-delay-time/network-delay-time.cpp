class Solution {
    int dijkstra(int n, vector<vector<pair<int, int>>> &adj, int start) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> dist(n, 1e9);

        dist[start] = 0;
        pq.push({0, start}); // {time/distance, starting_node}

        while(!pq.empty()) {

            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node])
                continue;

            for(auto &it : adj[node]) {

                int neigh = it.first;
                int wt    = it.second;

                if(dist[node] + wt < dist[neigh]) {
                    dist[neigh] = dist[node] + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int s = 0;
        for(int i = 0; i < dist.size(); i++){
            if(dist[i] == 1e9){
                return -1;
            }
            else{
                s = max(s, dist[i]);
            }
        }


        return s;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }
        return dijkstra(n, adj, k - 1);
    }
};