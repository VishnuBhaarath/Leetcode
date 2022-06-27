class Solution {
public:
    int countHousePlacements(int n) {
       
        long long int mod=1000000007;
        if(n==1){
            return 4;
        }
        if(n==2){
            return 9;
        }
      
        long long int prev1=1;
        long long int prev=2;
        for(int i=3;i<=n;i++){
          
            long long int curr=prev1+prev+1;
            prev1=prev;
            prev=curr;
            prev1=prev1%mod;
            prev=prev%mod;
        }
        long long int curr=prev;
        curr=curr%mod;
       
        
        long long int val=curr*curr;
        val=val%mod;
        val+=curr;
        val=val%mod;
        val+=curr;
        val=val%mod;
        val+=1;
        return val%mod;
    }
};