class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<vector<int>> v;
        for(int i=0;i<tasks.size();i++){
            v.push_back({tasks[i][1]-tasks[i][0],tasks[i][0],tasks[i][1]});
        }

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++){
            cout<<v[i][0];
            cout<<" ";
            cout<<v[i][1];
              cout<<" ";
            cout<<v[i][2];
            cout<<"\n";
        }
        int n=v.size();
        int ans=v[n-1][2];
        int sum=v[n-1][0];

        for(int i=n-2;i>=0;i--){
            if(sum<v[i][1]){
                int dif=v[i][1]-sum;
                ans+=dif;
                sum=v[i][1];
            }
            if(sum<v[i][2]){
                 int dif=v[i][2]-sum;
                 ans+=dif;
                 sum=v[i][2];
            }
            sum-=v[i][1];
        }
        return ans;
    }
};