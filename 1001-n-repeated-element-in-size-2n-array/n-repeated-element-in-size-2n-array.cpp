class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int val=0;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }
            else{
                return nums[i];
            }
        }
        return val;
    }
};