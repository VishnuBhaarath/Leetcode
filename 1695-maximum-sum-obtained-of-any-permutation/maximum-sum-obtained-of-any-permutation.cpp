class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        map<int,int> umap;
        int n=nums.size();
        vector<int> v(n+1,0);
        for(int i=0;i<requests.size();i++){
            umap[requests[i][0]]+=1;
            v[requests[i][0]]+=1;
            umap[requests[i][1]+1]-=1;
             v[requests[i][1]+1]-=1;
        }
        vector<int> v1(n+1,0);
        int cnt=0;
        for(int i=0;i<v.size();i++){
            cnt+=v[i];
            v1[i]=cnt;
        }
        sort(nums.begin(),nums.end());
        sort(v1.begin(),v1.end());
        int i=n-1;
        long long int sum=0;
        int mod=1e9+7;
        for(int j=v1.size()-1;j>=0;j--){
            if(v1[j]==0){
                break;
            }
          long long int val=  (long long)(nums[i])*(long long)(v1[j]);
          val%=mod;
          sum+=val;
          sum%=mod;
          i-=1;
        }
        return sum;
      
    }
};