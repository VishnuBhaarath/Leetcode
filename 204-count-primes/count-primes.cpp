class Solution {
public:
 
    int countPrimes(int n) {
        vector<int> dp(n+1,1);
        if(n<=2){
            return 0;
        }
        
        int cnt=0;
        for(int i=2;i<n;i++){
            if(dp[i]==1){
                cnt+=1;
              for(int j=(i*2);j<n;j+=i){
                dp[j]=0;
              }
            }
        }

       
        return cnt;
    }
};