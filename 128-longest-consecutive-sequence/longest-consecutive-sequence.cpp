class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int x : s) {
            if (s.find(x - 1) == s.end()) {      // x is the start of a sequence
                int cur = x;
                int cnt = 1;
                while (s.find(cur + 1) != s.end()) {
                    cur++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};