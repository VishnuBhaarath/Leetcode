class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        while(!pq.empty()){
            if(k==1){
                return pq.top();
            }
            pq.pop();
            k-=1;
        }
        return -1;
        
    }
};