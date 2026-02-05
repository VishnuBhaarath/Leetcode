class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s1;
        for(int i=0;i<nums.size();i++){
            s1.insert(nums[i]);
        }
        int l=nums.size()-k;
        if (l < s1.size()) {
        auto it = next(s1.begin(), l);
        return *it;
        cout << *it << endl;

    }
    return 3;
    }
};