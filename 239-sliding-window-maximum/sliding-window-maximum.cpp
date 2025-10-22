class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<k;i++){
            if(dq.empty()){
                dq.push_back(i);
            }
            else{
                if(nums[dq.back()]>nums[i]){
                    dq.push_back(i);
                }
                else{
                    while(nums[dq.back()]<=nums[i]){
                        dq.pop_back();
                        if(dq.empty()){
                            break;
                        }
                    }
                    dq.push_back(i);
                }
            }
        }
         vector<int> ans;
         ans.push_back(nums[dq.front()]);
         int i=0;
         int j=k;
         while(j<nums.size()){
            
            if(dq.front()<=i){
                dq.pop_front();
                
            }
            if(dq.empty()){
                dq.push_back(j);
            }
            else{
                if(nums[dq.back()]>nums[j]){
                    dq.push_back(j);
                }
                else{
                    while(nums[dq.back()]<=nums[j]){
                        dq.pop_back();
                        if(dq.empty()){
                            break;
                        }
                    }
                    dq.push_back(j);
                }

            }
           
            ans.push_back(nums[dq.front()]);
            j+=1;
            i+=1;
            
         }
        return ans;
    }
};