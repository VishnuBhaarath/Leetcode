class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
         int n=piles.size();
         int l=1;
     int r=piles[n-1];
     int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
           long long  int sum=0;
            for(int i=0;i<piles.size();i++){
                int q=piles[i]/m;
                int r=piles[i]%m;
                sum+=q;
               
                if(r!=0){
                    sum+=1;
                }
            }
            
            if(sum>h){
                l=m+1;
            }
            else{
                if(ans==-1){
                    ans=m;
                }
                else{
                    ans=min(ans,m);
                }
                r=m-1;
            }

        }
        return ans;
    }
};