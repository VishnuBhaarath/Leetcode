class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        int ans=dp[0];
        int sum=0;
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
           while((i-pq.top().second)>k){
             pq.pop();
             if(pq.empty()){
                break;
            }
           }
           int sum=nums[i];
           if(!pq.empty()){
              if(pq.top().first>=0){
            sum+=pq.top().first;
              }
              
              pq.push({sum,i});
           }
           pq.push({sum,i});
           ans=max(ans,sum);

        }
        


        return ans;
    }
};