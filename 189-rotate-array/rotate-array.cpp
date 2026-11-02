class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v=nums;
        for(int i=0;i<v.size();i++){
            int idx=(i+k)%n;
            nums[idx]=v[i];
        }
    }
};