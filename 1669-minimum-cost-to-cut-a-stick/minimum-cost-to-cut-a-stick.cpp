class Solution {
public:
    vector<vector<int>> dp;
    int func(vector<int>&cuts,int i,int j){

        if(j<i){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
           int val= cuts[j+1]-cuts[i-1]+func(cuts,k+1,j)+func(cuts,i,k-1);
           ans=min(ans,val);
        }
        return dp[i][j]=ans;
    }

    int minCost(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        vector<int> v;
        v.push_back(0);
        for(int i=0;i<cuts.size();i++){
            v.push_back(cuts[i]);
        }
        v.push_back(n);
        int m=v.size();
        dp.resize(m+2,vector<int>(m+2,0));
       // return func(v,1,m-2);

        for(int i=m-2;i>=1;i--){
            for(int j=1;j<=m-2;j++){
               
                if(j<i){
                   dp[i][j]=0;
                }
                else{ int ans=INT_MAX;
                for(int k=i;k<=j;k++){
                    int val= v[j+1]-v[i-1]+dp[k+1][j]+dp[i][k-1];
                    ans=min(ans,val);
                }
                dp[i][j]=ans;
                }
                
            }
        }

        return dp[1][m-2];
    }
};