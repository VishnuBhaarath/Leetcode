class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int i=0;
        for(int j=0;j<nums.size();j++){
             if(q.empty()){
                q.push_back(j);
             }
             else{
                while(nums[j]>nums[q.back()]){
                    q.pop_back();
                    if(q.empty()){
                        break;
                    }
                }
                q.push_back(j);
             }
             while(q.front()<i){
                q.pop_front();
             }
             if(j-i+1>=k){
                ans.push_back(nums[q.front()]);
                i+=1;
             }

             
        }
        return ans;

    }
};