class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
                vector<vector<int>> v;
        int mod=1e9+7;
        for(int i=0;i<speed.size();i++){
           
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.begin(),v.end());
      

       
    
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

     //   int n=v[0].size();
        long long int sum=0;
        long long int ans=0;
        for(int i=n-1;i>=0;i--){
             if(k>0){
               sum+=v[i][1];
               k-=1;
               pq.push({v[i][1],v[i][0]});
               long long int temp=sum*v[i][0];
               ans=max(ans,temp);
             }
             else{
                pair<int,int> p=pq.top();
               
                if(p.first<v[i][1]){
                    pq.pop();
                    pq.push({v[i][1],v[i][0]});
                    sum-=p.first;
                    sum+=v[i][1];
                    long long int temp=sum*v[i][0];
                    ans=max(ans,temp);
                }
             }
           
        }
        return ans%mod;

    }
};