class Solution {
public:
  int func(int l, int r, int k, vector<int>& v) {
        int best = l;
        for (int s = l; s <= r; s++) {
            if (v[s + k] - v[s] > v[best + k] - v[best]) {
                best = s;
            }
        }
        return best;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
          vector<int> v;
        vector<int> v1;
        int n = nums.size();
        v.push_back(0);
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int temp = v[v.size() - 1];
            v.push_back(nums[i] + temp);
        }
        v1.push_back(0);
        v1.push_back(nums[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            int temp = v1[v1.size() - 1];
            v1.push_back(nums[i] + temp);
        }

        int best = -1;
        vector<int> ans = {0, 0, 0};

        int j = 2 * k;                      // j = end (exclusive) of the middle window
        while (j <= n - k) {
            int mid = j - k;
            int midSum = v[j] - v[j - k];

            int x = func(0, j - 2 * k, k, v);       // best first window, ends before mid starts
            int y = func(j, n - k, k, v);           // best last window, starts after mid ends

            int total = (v[x + k] - v[x]) + midSum + (v[y + k] - v[y]);
            if (total > best) {                     // strict > keeps the smallest mid on ties
                best = total;
                ans = {x, mid, y};
            }
            j += 1;
        }
        return ans;
    }
};