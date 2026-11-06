class Solution {
public:
    priority_queue<long long int> pq;
    priority_queue<long long int,vector<long long int>,greater<long long int>> pq1;
    map<long long int,long long int> umap;
    long long int sz=0;
    long long int sz1=0;
    long long sum=0;
   long long ans=LLONG_MAX;

    void add(int num,int k){
        prune();
        if(sz<k){
            if(sz1>0){                      // added: pq1 has live elements, so compare through pq1
            pq1.push(num);
            long long tp=pq1.top();     // smallest of pq1 + num
            pq1.pop();
            prune();
            pq.push(tp);
            sum+=tp;
            sz+=1;
        }
        else{                           // original path (initial fill)
            pq.push(num);
            sum+=num;
            sz+=1;
        }
        }
        else{
            pq.push(num);
            sum+=num;
            long long tp=pq.top();
            pq.pop();
            prune();
            sum-=tp;
            pq1.push(tp);
            sz1+=1;
        }
    }

    void remove(int num){
        if(!pq.empty() && num<=pq.top()){   // lives in pq (counted in sum)
    sum-=num; sz-=1;
    umap[num]+=1;
    // if num==pq.top(), prune now so pq.top() stays live
}
else{                               // lives in pq1
    sz1-=1;
    umap[num]+=1;
}
prune();
    }

    void prune(){
         while(!pq.empty() && umap[pq.top()]>0){
              umap[pq.top()]-=1;
              pq.pop();
         }

         while(!pq1.empty() && umap[pq1.top()]>0){
             umap[pq1.top()]-=1;
             pq1.pop();
         }
    }
    

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        sum+=nums[0];
        for(int j=1;j<=min(n-1,1+dist);j++){
            add(nums[j],k-1);
        }
       
        int i=1;
        int j=dist+2;
  
        ans=min(ans,sum);
       
   
    
        while(j<n){
           
            remove(nums[i]);
            add(nums[j],k-1);
           
            ans=min(ans,sum);
            i+=1;
            j+=1;
        }
        return ans;
    }
};