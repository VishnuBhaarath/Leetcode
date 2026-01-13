class Solution {
public:
    long long int check(long long int m, vector<int>& bloomDay,long long int k){
        long long int i=0;
        long long int l=0;
        long long int cnt=0;
        while(i<bloomDay.size()){
            if(bloomDay[i]<=m){
                l+=1;
            }
            else{
                l=0;
            }
            if(l==k){
                cnt+=1;
                l=0;
            }
            i+=1;
        }
       return cnt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n=bloomDay.size();
        long long val1=(long long)(m) * (long long)(k);
        if(val1>n){
            return -1;
        }
        long long int l=bloomDay[0];
        long long int r=bloomDay[1];
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<l){
                l=bloomDay[i];
            }
            if(bloomDay[i]>r){
                r=bloomDay[i];
            }
        }
long long int ans=-1;
        while(l<=r){
            long long int m1=l+(r-l)/2;
            long long int val=check(m1,bloomDay,k);
            if(val>=m){
                ans=m1;
                r=m1-1;
            }
            else{
                l=m1+1;
            }
        }
        return ans;
    }
};