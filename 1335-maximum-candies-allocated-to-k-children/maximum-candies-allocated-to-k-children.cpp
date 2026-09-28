class Solution {
public:
    int check(vector<int>&candies,long long m, long long k){
         for(int i=0;i<candies.size();i++){
              int q=candies[i]/m;
              k-=q;
              if(k<=0){
                return 1;
              }
         }
         return 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long int l=1;
        long long int r=0;
        for(int i=0;i<candies.size();i++){
            r=max(r,(long long)(candies[i]));
        }
    int idx=0;
        while(l<=r){
            long long int m=l+(r-l)/2;
            if(check(candies,m,k)){
                idx=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            
        }
        return idx;
    }
};