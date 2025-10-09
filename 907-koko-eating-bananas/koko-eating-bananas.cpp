class Solution {
public:
    bool check(vector<int>& piles,int m,int h){
        int cnt=0;
        for(int i=0;i<piles.size();i++){
            int q=piles[i]/m;
            cnt+=q;
            if(piles[i]%m !=0){
                cnt+=1;
            }
            if(cnt>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        if(h==n){
            return piles[n-1];
        }
        int l=1;
        int r=piles[n-1];
        int idx=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(piles,m,h)){
                if(idx==-1){
                    idx=m;
                }
                else{
                    idx=min(idx,m);
                }
                r=m-1;
            } 
            else{
                l=m+1;
            }

        }
         return idx;
    }
};