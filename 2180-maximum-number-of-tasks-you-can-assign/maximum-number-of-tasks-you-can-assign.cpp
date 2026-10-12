class Solution {
public:
 bool check(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = workers.size();
        vector<int> taken(k, 0);
        priority_queue<int> pq;      // max-heap of reachable task indices
        int lo = 0;                  // easiest remaining task
        int ptr = 0;                 // next task to unlock

        for (int w = m - k; w < m; w++) {      // k strongest workers, weakest first
            int power = workers[w];

            // unlock all tasks this worker can do with a pill
            while (ptr < k && tasks[ptr] <= power + strength) {
                pq.push(ptr);
                ptr++;
            }

            // move lo to the easiest task not yet taken
            while (lo < k && taken[lo] == 1) {
                lo++;
            }

            if (lo < k && tasks[lo] <= power) {
                // no pill needed
                taken[lo] = 1;
            }
            else {
                // must use a pill
                if (pills == 0) return false;

                // remove already-taken tasks from the top (lazy deletion)
                while (!pq.empty() && taken[pq.top()] == 1) {
                    pq.pop();
                }
                if (pq.empty()) return false;

                taken[pq.top()] = 1;   // hardest reachable task
                pq.pop();
                pills--;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = 0, r = min(n, m);
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid, tasks, workers, pills, strength)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};