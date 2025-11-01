class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            v[tasks[i] - 'A'] += 1;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 0) {
                pq.push({v[i], i});
            }
        }
        int cnt = 0;
        if(n==0){
            return tasks.size();
        }
        while (!pq.empty()) {
            priority_queue<pair<int, int>> pq1;
            int m = 0;

            while (!pq.empty()) {
                pair<int, int> p = pq.top();
                pq.pop();
                p.first -= 1;
                m += 1;
                cnt += 1;
                if (p.first > 0) {
                    pq1.push(p);
                }
                if (m == (n+1)) {
                    break;
                }
            }
            if(!pq1.empty()){
            cnt += (n+1 - m);}
            while (!pq1.empty()) {
                pq.push(pq1.top());
                pq1.pop();
            }
        }

        return cnt;
    }
};