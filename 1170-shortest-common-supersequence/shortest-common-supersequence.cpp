class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(str1[i]!=str2[j]){
                    if((i-1)>=0){
                        dp[i][j]=dp[i-1][j];
                    }
                    if((j-1)>=0){
                        dp[i][j]=max(dp[i][j],dp[i][j-1]);
                    }
                }
                else{
                     if((i-1)>=0 &&(j-1)>=0){
                        dp[i][j]=1+dp[i-1][j-1];
                     }
                     else{
                        dp[i][j]=1;
                     }
                }
            }
        }
        string s1="";

       
        int i=n-1;
        int j=m-1;
    
        while(i>=0 && j>=0){
            if(str1[i]==str2[j]){
                   s1+=str1[i];
                   i-=1;
                   j-=1;
            }
            else {
                if((i-1)>=0 && (j-1)>=0){
                    if(dp[i-1][j]>dp[i][j-1]){
                       s1+=str1[i];
                       i-=1;
                    }
                    else{
                       s1+=str2[j];
                       j-=1;
                    }
                }
                else if((j-1)>=0){
                    s1+=str2[j];
                    j-=1;
                }
                else if((i-1)>=0){
                    s1+=str1[i];
                    i-=1;
                }
                else{
                    break;
                }
               
            }
        }
        while(i>=0){
            s1+=str1[i];
            i-=1;
        }
        while(j>=0){
            s1+=str2[j];
            j-=1;
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
};