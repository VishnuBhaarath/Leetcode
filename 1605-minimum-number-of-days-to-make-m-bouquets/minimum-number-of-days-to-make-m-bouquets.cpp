class Solution {
public:
    int check(vector<int> & bloomDay,int idx,int m,int k){
         int n=bloomDay.size();
         vector<int> v(n,0);
         for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=idx){
                v[i]=1;
            }
         }
        int val=0;
        int cnt=0;
     
        for(int i=0;i<v.size();i++){
        
            if(v[i]==1){
                cnt+=1;
            }
            else{
                cnt=0;
            }
            if(cnt==k){
                 val+=1;
                 cnt=0;
            }
        }
   
        return val;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n=bloomDay.size();
        if(n < (long long int)(m)*(long long int)(k)){
            return -1;
        }

      

        int l=1e9;
        int r=0;
        for(int i=0;i<bloomDay.size();i++){
            l=min(l,bloomDay[i]);
            r=max(r,bloomDay[i]);
        }
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int val=check(bloomDay,mid,m,k);
            if(val>=m){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};