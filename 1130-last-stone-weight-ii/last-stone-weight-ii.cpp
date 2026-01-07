class Solution {
public:
    int func(vector<int>& stones,int i, int sum){
      
        
        if(i==stones.size()){
            return abs(sum);
        }

        return min(func(stones,i+1,sum+stones[i]),func(stones,i+1,sum-stones[i]));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int m=0;
        for(int i=0;i<stones.size();i++){
            m+=stones[i];
        }
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        int ans=m;
        for(int i=0;i<stones.size();i++){
             for(int j=0;j<dp[0].size();j++){
                 if(i==0){
                    dp[i][stones[i]]=1;
                 }
                 else{
                    if(dp[i-1][j]==1){
                        dp[i][abs(j+stones[i])]=1;
                        dp[i][abs(j-stones[i])]=1;
                        if(i==n-1){
                        ans=min(ans,abs(j+stones[i]));
                        ans=min(ans,abs(j-stones[i]));
                    }
                    }
                    
                 }
             }
        }
        

        return ans;
       
    }
};