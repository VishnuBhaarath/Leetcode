class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> umap;
        for (int i = 0; i < hand.size(); i++) {
            umap[hand[i]] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto x : umap) {
            pq.push({x.first, x.second});
        }
        while (!pq.empty()) {
            int sz = 0;
            int prev = -1;
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq1;
            while (!pq.empty()) {
                pair<int, int> p = pq.top();
                pq.pop();

                p.second -= 1;
                if (sz > 0) {
                    if (prev + 1 != p.first) {
                        return false;
                    }
                }
                sz += 1;
                prev = p.first;

                if (p.second > 0)
                    pq1.push(p);
                if (sz == groupSize) {
                    break;
                }
            }

            if (sz != groupSize) {
                return false;
            }
            while (!pq1.empty()) {
                pq.push(pq1.top());
                pq1.pop();
            }
        }
        return true;
    }
};