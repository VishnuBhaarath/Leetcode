class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int st = nums[n - 1];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int left = mid - 1;
            int right = mid + 1;
            if (nums[mid] > st) {
                if (target <= st) {
                    l = mid + 1;
                } else {
                    if (target < nums[mid]) {
                        r = mid - 1;
                    } else if (target > nums[mid]) {
                        l = mid + 1;
                    } else if (target == nums[mid]) {
                        return mid;
                    }
                }
            } else if (nums[mid] <= st) {
                if (target > st) {
                    r = mid - 1;
                } else {
                    if (target > nums[mid]) {
                        l = mid + 1;
                    } else if (target < nums[mid]) {
                        r = mid - 1;
                    } else if (target == nums[mid]) {
                        return mid;
                    }
                }
            }
        }
        return -1;
    }
};