class Solution {
public:
    bool ans=false;
    void func(vector<int>& piles,int t,int sum1,int sum2,int i,int j){
        if(j<i){
            if(sum1>sum2){
                ans=true;
            }
            return;
        }
        if(t==0){
            func(piles,1,sum1+piles[i],sum2,i+1,j);
            func(piles,1,sum1+piles[j],sum2,i,j-1);
        }
        if(t==1){
            func(piles,0,sum1,sum2+piles[i],i+1,j);
            func(piles,0,sum1,sum2+piles[j],i,j-1);
        }
    }
    bool stoneGame(vector<int>& piles) {
        return true;
        int n=piles.size();
        func(piles,0,0,0,0,n-1);
        return ans;
    }
};