class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefixSum = 0, res = 0;
        unordered_map<int, int> count;
        count[0] = 1;

        for (int& num : nums) {
            prefixSum += num;
            res += count[prefixSum - goal];
            count[prefixSum]++;
        }

        return res;
    }
};