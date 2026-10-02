class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> events(102, 0);

        // Create events
        for (auto &v : nums) {
            int l = v[0];
            int r = v[1];

            events[l] += 1;       // car starts
            events[r + 1] -= 1;   // car ends after r
        }

        int cnt = 0;
        int ans = 0;

        // Sweep from left to right
        for (int i = 1; i <= 100; i++) {
            cnt += events[i];

            if (cnt > 0) {
                ans++;
            }
        }

        return ans;
    }
};