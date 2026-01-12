class Solution {
public:
    vector<vector<int>> dp1;
    int check(int i,int j,string s1,string s2){
        if(i==s1.size() && j==s2.size()){
            return 0;
        }
        if(i==s1.size() && j!=s2.size()){
            int sum=0;
            while(j<s2.size()){
                sum+=s2[j];
                j+=1;
            }
            return sum;
        }

        if(i!=s1.size() && j==s2.size()){
            int sum=0;
            while(i<s1.size()){
                sum+=(s1[i]-0);
                i+=1;
            }
            return sum;
        }
        if(dp1[i][j]!=-1){
            return dp1[i][j];
        }
        if(s1[i]==s2[j]){
            return dp1[i][j]=check(i+1,j+1,s1,s2);
        }
        else{
            return dp1[i][j]=min(s2[j]+check(i,j+1,s1,s2), s1[i]+check(i+1,j,s1,s2));
        }
       return 0;
    }


    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        dp1.resize(n+1,vector<int>(m+1,-1));
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]=s1[i]+dp[i][j];
                    ans=max(ans,dp[i+1][j+1]);
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                     ans=max(ans,dp[i+1][j+1]);
                }
            }
        }
       
        int sum=0;
        for(int i=0;i<s1.size();i++){
            sum+=s1[i];
        }
        for(int i=0;i<s2.size();i++){
            sum+=s2[i];
        }
        sum-=(2*ans);
       // return check(0,0,s1,s2);
       return sum;
    }
};