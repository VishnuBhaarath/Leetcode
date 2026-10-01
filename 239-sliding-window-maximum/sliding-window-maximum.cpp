class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(pq.empty()){
                pq.push({nums[i],i});
            }
            else{
            int t=0;
            while(nums[i]>pq.top().first){
                pq.pop();
                if(pq.empty()){
                    t=1;
                    pq.push({nums[i],i});
                    break;
                }
            }
            if(t==0){
                pq.push({nums[i],i});
            }
            }
        }
        ans.push_back(pq.top().first);
     
        int i=0;
        for(int j=k;j<nums.size();j++){
            while(nums[j]>pq.top().first){
                pq.pop();
                if(pq.empty()){
                    break;
                }
            }
            pq.push({nums[j],j});
         
            while(pq.top().second<=i){
                pq.pop();
                if(pq.empty()){
                    break;
                }
            }
        
            i+=1;
            ans.push_back(pq.top().first);
        }

       

        return ans;

    }
};