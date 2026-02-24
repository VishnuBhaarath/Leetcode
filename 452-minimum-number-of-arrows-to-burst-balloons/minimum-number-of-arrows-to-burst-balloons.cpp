class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& ans) {
         sort(ans.begin(),ans.end());
    int st=ans[0][0];
    int end=ans[0][1];
    
    int j=1;
    int cnt=1;
    while(j<ans.size()){
        if(ans[j][0]>end){
            end=ans[j][1];
            st=ans[j][0];
            cnt+=1;
        }
        else{
            st=ans[j][0];
            end=min(ans[j][1],end);
            
        }
        j+=1;
    }
   // cout<<cnt;
   return cnt;
    }
};