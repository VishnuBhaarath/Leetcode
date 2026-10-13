class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq1;

      

        int l=0;
        int r=0;
        int ans=1;
        while(r<nums.size()){
            if(pq.empty()){
                pq.push({nums[r],r});
                pq1.push({nums[r],r});
            }
            else{
              
               int t=0;
               while(abs(pq.top().first-nums[r])>limit){
                    l=max(l,pq.top().second);
                    t=1;
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
               }
                while(abs(pq1.top().first-nums[r])>limit){
                   l=max(l,pq1.top().second);
                   t=1;
                   pq1.pop();
                   if(pq1.empty()){
                    break;
                   }
               }
               if(t==1){
                l+=1;
               }
               if(!pq.empty()){
                  while(abs(pq.top().second)<l){
                     pq.pop();
                     if(pq.empty()){
                        break;
                     }
                  }
               }

              

               if(!pq1.empty()){
                  while(pq1.top().second<l){
                    pq1.pop();
                    if(pq1.empty()){
                        break;
                    }
                  }
               }

                
                pq.push({nums[r],r});
                pq1.push({nums[r],r});
            }
           
            ans=max(ans,(r-l+1));
            r+=1;
        }

        return ans;
    }
};