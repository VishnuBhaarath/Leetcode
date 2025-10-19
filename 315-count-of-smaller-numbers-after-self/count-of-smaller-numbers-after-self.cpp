class Solution {
public:
 vector<int> counts;
    
    void merge(vector<pair<int, int>>& nums, int l, int m, int r) {
        vector<pair<int, int>> temp;
        int i = l;      // pointer for left subarray
        int j = m + 1;  // pointer for right subarray
        
        while (i <= m && j <= r) {
            if (nums[i].first <= nums[j].first) {
                // When we take from left subarray, count how many 
                // elements from right subarray are smaller
                counts[nums[i].second] += (j - (m + 1));
                temp.push_back(nums[i]);
                i++;
            } else {
                // Take from right subarray
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        // Process remaining elements from left subarray
        while (i <= m) {
            // All elements from right subarray have been processed
            // so add the count of all elements from right subarray
            counts[nums[i].second] += (j - (m + 1));
            temp.push_back(nums[i]);
            i++;
        }
        
        // Process remaining elements from right subarray
        while (j <= r) {
            temp.push_back(nums[j]);
            j++;
        }
        
        // Copy back to original array
        for (int i = l; i <= r; i++) {
            nums[i] = temp[i - l];
        }
    }


 void mergeSort(vector<pair<int, int>>& nums, int l, int r) {
        if (l >= r) return;
        
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }

    
    
    vector<int> countSmaller(vector<int>& nums) {
         int n = nums.size();
        counts.resize(n, 0);
        
        // Create pairs of (value, original_index)
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < n; i++) {
            indexedNums.push_back({nums[i], i});
        }
        
        mergeSort(indexedNums, 0, n - 1);
        
        return counts;
        
    }
};