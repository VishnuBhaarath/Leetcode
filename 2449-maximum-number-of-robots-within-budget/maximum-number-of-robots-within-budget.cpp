class Solution {
public:
//  int ans=-1;
    int check(int k,vector<int>& chargeTimes, vector<int>& runningCosts, long long budget){
int ans=-1;
        long long  sum=0;
        int l=0;
        int r=0;
        int n=chargeTimes.size();
        priority_queue<pair<int,int>> pq;
        while(r<n){
            if(r-l+1 <=k){
                sum+=runningCosts[r];
                if(pq.empty()){
                    pq.push({chargeTimes[r],r});
                }
                else if(chargeTimes[r]<pq.top().first){
                    pq.push({chargeTimes[r],r});
                }
                else{
                    while(pq.top().first<= chargeTimes[r]){
                        pq.pop();
                        if(pq.empty()){
                            break;
                        }
                    }
                    pq.push({chargeTimes[r],r});
                }
              
               if(r-l+1==k){
                long long val=(long long)((long long)((r-l+1))*(long long)(sum)) + (long long)(pq.top().first);
                if(val<=budget){
                    if(ans==-1){
                        ans=r-l+1;
                    }
                    else{
                        ans=max(ans,r-l+1);
                    }
                }
                }
               
            }
            else{
                sum-=runningCosts[l];
                
                while(pq.top().second<=l){
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
                }
                  sum+=runningCosts[r];
                  if(pq.empty()){
                    pq.push({chargeTimes[r],r});
                } 
                else if(chargeTimes[r]<pq.top().first){
                    pq.push({chargeTimes[r],r});
                }
                else{
                    while(pq.top().first<= chargeTimes[r]){
                        pq.pop();
                        if(pq.empty()){
                            break;
                        }
                    }
                    pq.push({chargeTimes[r],r});
                }
                l+=1;
              ;
                    if(r-l+1==k){
                         long long val=(long long)((long long)((r-l+1))*(long long)(sum)) + (long long)(pq.top().first);
                       if(val<=budget){
                    if(ans==-1){
                        ans=r-l+1;
                    }
                    else{
                        ans=max(ans,r-l+1);
                    }
                    }
                }
                
            }
            r+=1;
        }
       
        return ans;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        vector<int> v;
        v.push_back(0);
      
       int n=chargeTimes.size();
       
       int l=1;
       int r=n;
       int idx=0;
       while(l<=r){
        int m=l+(r-l)/2;
        int val=check(m,chargeTimes,runningCosts,budget);
        if(val==-1){
            r=m-1;
        }
        else{
            idx=m;
            l=m+1;
        }
       }
       
        
        return idx;
    }
};