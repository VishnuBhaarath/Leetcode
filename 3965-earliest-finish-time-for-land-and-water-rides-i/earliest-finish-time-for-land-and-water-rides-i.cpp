class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        vector<vector<int>> v;
        vector<vector<int>> v1;

        for(int i=0;i<landStartTime.size();i++){
            v.push_back({landStartTime[i],landDuration[i]});
        }

        for(int i=0;i<waterStartTime.size();i++){
            v1.push_back({waterStartTime[i],waterDuration[i]});
        }



        int ans=-1;
        for(int i=0;i<v.size();i++){
            int l=v[i][0];
            int r=v[i][1]+v[i][0];
           
            for(int j=0;j<v1.size();j++){
                int val=0;
                if(v1[j][0]<=r){
                    val=r+v1[j][1];
                }
                else{
                     val=v1[j][0]+v1[j][1];
                }
                if(ans==-1){
                    ans=val;
                }
                else{
                    ans=min(ans,val);
                }

            }
        }

         for(int i=0;i<v1.size();i++){
            int l=v1[i][0];
            int r=v1[i][1]+v1[i][0];
           
            for(int j=0;j<v.size();j++){
                int val=0;
                if(v[j][0]<=r){
                    val=r+v[j][1];
                }
                else{
                     val=v[j][0]+v[j][1];
                }
                if(ans==-1){
                    ans=val;
                }
                else{
                    ans=min(ans,val);
                }

            }
        }
        return ans;
    }
};