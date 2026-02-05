class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<long long int,long long int>> v;
        for(int i=0;i<nums2.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long int sum=0;
        long long int ans=0;
        long long int n=nums2.size();
        for(int i=n-1;i>=0;i--){
             
             if(pq.size()<k){
                pq.push(v[i].second);
                sum+=v[i].second;
                if(pq.size()==k){
                    long long int val=v[i].first*sum;
                 ans=max(ans,val);
                }
             }
             else if(pq.size()==k){
                long long int tp=pq.top();
                 if(tp<v[i].second){
                    sum-=tp;
                    sum+=v[i].second;
                    pq.pop();
                    pq.push(v[i].second);
                 }
                long long int val=v[i].first*sum;
                 ans=max(ans,val);
             }
        }
        return ans;
    }
};