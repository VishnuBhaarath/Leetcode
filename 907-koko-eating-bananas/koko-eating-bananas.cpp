class Solution {
public:
    long long int check(int m,vector<int>& piles){
        long long int days=0;
        for(int i=0;i<piles.size();i++){
            int q=piles[i]/m;
            days+=q;
            if(piles[i]%m !=0){
                days+=1;
            }
        }
        return days;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int r=piles[0];
        for(int i=0;i<piles.size();i++){
            if(piles[i]>r){
                r=piles[i];
            }
        }
        long long int ans=-1;
        long long int l=1;
        while(l<=r){
            long long int m=l+(r-l)/2;
            long long int val=check(m,piles);
           
            if(val<=h){
                ans=m;
                r=m-1;
            }
            else{
                
                l=m+1;
            }

        }
        return ans;
    }
};