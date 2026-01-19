class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<vector<int>> v;
        for(int i=0;i<costs.size();i++){
            v.push_back({costs[i],capacity[i]});
        }
        sort(v.begin(),v.end());
        int n=costs.size();
        vector<int> psum(n,0);
        psum[0]=v[0][1];
        for(int i=1;i<psum.size();i++){
            psum[i]=max(psum[i-1],v[i][1]);
        }
        int ans=0;
        for(int i=0;i<costs.size();i++){
          
            if(v[i][0]<budget){
                ans=max(ans,v[i][1]);
            }
            int l=0;
            int r=i-1;
            if(budget-v[i][0]>0){
                int val=0;
            while(l<=r){
                int m=l+(r-l)/2;
                if(v[m][0]<budget-v[i][0]){
                    val=max(val,psum[m]);
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
            ans=max(ans,val+v[i][1]);
            }
          
        }
        return ans;
    }
};