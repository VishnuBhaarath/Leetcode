class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long int> dp(n+1,0);
        long long int mod=1000000007;
        if(n==1){
            return 4;
        }
        if(n==2){
            return 9;
        }
        dp[1]=1;
        dp[2]=2;
        int prev1=1;
        int prev=2;
        for(int i=3;i<dp.size();i++){
            dp[i]=dp[i-1]+dp[i-2]+1;
            dp[i]%=mod;
        }
       
        long long int temp=dp[n]%mod;
        
        long long int val=temp*temp;
        val=val%mod;
        val+=temp;
        val=val%mod;
        val+=temp;
        val=val%mod;;
        val+=1;
        return val%mod;
    }
};