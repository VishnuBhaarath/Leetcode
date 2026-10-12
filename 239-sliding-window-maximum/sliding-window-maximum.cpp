class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int l=0;
        int r=0;
        int n=nums.size();
        vector<int> v;
        while(r<n){
            if(r-l+1<=k){
             if(pq.empty()){
                pq.push({nums[r],r});
             }
             else if(nums[r]<pq.top().first){
                pq.push({nums[r],r});
             }
             else{
                while(nums[r]>=pq.top().first){
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
                }
                pq.push({nums[r],r});
              
               
             }
              if(r-l+1==k){
                  
                    v.push_back(pq.top().first);
                }
             }
             else{
                 while(pq.top().second<=l){
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
                 }
                 pq.push({nums[r],r});
                 l+=1;
              
                  if(r-l+1==k){
                     cout<<pq.top().first;
                   
                    v.push_back(pq.top().first);
                }
           
             }
            r+=1;
        }
        return v;
    }
};