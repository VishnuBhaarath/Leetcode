class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        auto it=*s.rbegin();
        v.push_back(it);
        int r=k;
        int l=0;
        while(r<nums.size()){
            s.insert(nums[r]);
        
            s.erase(s.find(nums[l]));
            auto it1=*s.rbegin();
            v.push_back(it1);
            l+=1;
            r+=1;
        }
        return v;

    }
};