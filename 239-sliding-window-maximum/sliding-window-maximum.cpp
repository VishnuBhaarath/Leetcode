class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
      
        priority_queue<pair<int,int>> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(q.empty()){
                q.push({nums[i],i});
            }
            else{
                while(nums[i]>q.top().first){
                    q.pop();
                    if(q.empty()){
                        break;
                    }
                }
                q.push({nums[i],i});
            }
        }
       
      ans.push_back(q.top().first);
    
      int r=k;
      int l=0;
      while(r<n){
        if(q.empty()){
            q.push({nums[r],r});
        }
        else{
        while(q.top().second<=l){
            q.pop();
            if(q.empty()){
                break;
            }
        }
        if(!q.empty()){
        while(nums[r]>q.top().first){
                    q.pop();
                    if(q.empty()){
                        break;
                    }
                }
             q.push({nums[r],r});   
        }
        else{
             q.push({nums[r],r}); 
        }
        }
        
         l+=1;
         r+=1;
         while(q.top().second < l){
            q.pop();
         }
         
         ans.push_back(q.top().first);
       

      }
      return ans;
    }
};