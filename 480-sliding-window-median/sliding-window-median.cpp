class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s1;  // max heap (smaller half)
        multiset<int> s2;  // min heap (larger half)
        vector<double> ans;
        int i = 0;
        int m = nums.size();
        
        // Build initial window
        while(i < k) {
            s1.insert(nums[i]);
            auto tp = *s1.rbegin();
            s2.insert(tp);
            s1.erase(s1.find(tp));
            
            if(s2.size() > s1.size()) {
                auto tp = *s2.begin();
                s2.erase(s2.find(tp));
                s1.insert(tp);
            }
            i++;
        }
        
        // Add first median
        int n = s2.size() + s1.size();
        if((n % 2) == 0) {
            double val = (double)(*s1.rbegin()) + (double)(*s2.begin());
            ans.push_back(val / 2);
        }
        else {
            double val = *s1.rbegin();
            ans.push_back(val);
        }
        
        int j = 0;
        while(i < m) {
            // Remove the outgoing element
            if(s1.find(nums[j]) != s1.end()) {
                s1.erase(s1.find(nums[j]));
            }
            else {
                s2.erase(s2.find(nums[j]));
            }
            
            // Add the incoming element
            s1.insert(nums[i]);
            auto tp = *s1.rbegin();
            s2.insert(tp);
            s1.erase(s1.find(tp));
            
            // Rebalance if needed
            if(s2.size() > s1.size()) {
                auto tp = *s2.begin();
                s2.erase(s2.find(tp));
                s1.insert(tp);
            }
            else if(s1.size() > s2.size() + 1) {
                auto tp = *s1.rbegin();
                s1.erase(s1.find(tp));
                s2.insert(tp);
            }
            
            i++;
            j++;
            
            // Calculate median
            n = s2.size() + s1.size();
            if((n % 2) == 0) {
                double val = (double)(*s1.rbegin()) + (double)(*s2.begin());
                ans.push_back(val / 2);
            }
            else {
                double val = *s1.rbegin();
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};