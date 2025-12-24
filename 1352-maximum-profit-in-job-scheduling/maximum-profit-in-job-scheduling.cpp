class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> dp;
        for(int i=0;i<startTime.size();i++){
            dp.push_back({endTime[i],startTime[i],profit[i]});
        }

        sort(dp.begin(),dp.end());
        int n=startTime.size();
        vector<int> dp1(n,0);
        int ans=0;
        for(int i=0;i<startTime.size();i++){
            dp1[i]=dp[i][2];
            int l=0;
            int r=i-1;
            int st=dp[i][1];
            cout<<st;
            cout<<" ";
            int end=-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(st>=dp[m][0]){
                    end=m;
                    l=m+1;
                }
                else{
                    r=m-1;
                }

            }
            cout<<end;
            cout<<"\n";
            if(end==-1){
                if((i-1)>=0){
                    dp1[i]=max(dp1[i],dp1[i-1]);
                }
            }
            else{
                dp1[i]=max(dp1[i-1],dp[i][2]+dp1[end]);
            }
      
            ans=max(ans,dp1[i]);
        
        }

        for(int i=0;i<dp1.size();i++){
            cout<<dp1[i];
            cout<<" ";
        }
        cout<<"\n";
       
        return ans;
    }
};