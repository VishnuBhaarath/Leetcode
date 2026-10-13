class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans=-1;
        int l=0;
        int r=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=nums.size();
        int sum=0;
      //  int ans=-1;
        while(r<n){
            sum+=nums[r];
            
            if(!pq.empty()){
                int val=0;
                int l1=l;
                int t=0;
                while(sum-pq.top().first >=k){
                    if(pq.top().second>=l1){
                        l1=pq.top().second;
                        t=1;
                        val=pq.top().first;
                    }
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
                }
             //   sum-=val;
                l=l1;
                if(!pq.empty()){
                    while(pq.top().second<l){
                        pq.pop();
                        if(pq.empty()){
                            break;
                        }
                    }
                }
                if(t==1){
                l+=1;}
                if(sum>=k){
                int sz=(r-l+1);
                if(ans==-1){
                    ans=sz;
                }
                else{
                    ans=min(ans,sz);
                }}

            }
            else{
                if(sum>=k){
                    int sz=(r-l+1);
                if(ans==-1){
                    ans=sz;
                }
                else{
                    ans=min(ans,sz);
                }
                }
            }
           
            pq.push({sum,r});
             if(sum<0){
                l=r+1;
                sum=0;
            }
            
            r+=1;
        }

        return ans;
    }
};