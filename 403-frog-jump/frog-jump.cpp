class Solution {
public:
    vector<vector<int>> dp;
    int t=0;
    int  func(vector<int>&stones,int i, int k,int n){
        
         if(i>=n || i<0){
            return 0;
         }
         if(i==n-1){
            t=1;
            return 1;
         }
         if(k<0){
            return 0;
         }
         if(t==1){
            return 1;
         }
         
         if(dp[i][k]!=-1){
            return dp[i][k];
         }
         int x=stones[i]+(k-1);
         int y=stones[i]+k;
         int z=stones[i]+k+1;
         int val1=-1;
         int val2=-1;
         int val3=-1;
         for(int j=i+1;j<stones.size();j++){
            if(stones[j]==x){
                
                val1=func(stones,j,k-1,n);
            }
            if(stones[j]==y){
                
                val2=func(stones,j,k,n);
            }
            if(stones[j]==z){
                val3=func(stones,j,k+1,n);
            }
            if(val1==1 || val2==1 || val3==1){
                dp[i][k]=1;
            }
            else{
                dp[i][k]=0;
            }

         }
         
        
        return 0;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        dp.resize(n+1,vector<int>(10000,-1));
        if(stones[0]+1 !=stones[1]){
            return false;
        }
        func(stones,1,1,n);
        if(t==0){
            return false;
        }
        return true;
    }
};