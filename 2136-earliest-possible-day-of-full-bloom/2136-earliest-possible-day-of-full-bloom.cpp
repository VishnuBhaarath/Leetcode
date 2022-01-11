class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<growTime.size();i++){
            pq.push({growTime[i],i});
        }
        int st=0;
        int ans=0;
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            
            st+=plantTime[p.second];
            int val=st+p.first;
            val+=1;
            ans=max(ans,val);
           
            pq.pop();
        }
        ans-=1;
       
        return ans;
    }
};