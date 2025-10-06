class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int start=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        cout<<start;
        if(start==nums.size() || nums[start]!=target){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        v.push_back(start);
        int end=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        v.push_back(end-1);

        return v;

    }
};