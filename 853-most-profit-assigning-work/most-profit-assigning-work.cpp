class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int n=profit.size();
        for(int i=0;i<profit.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }

         std::sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });
       
        sort(worker.begin(),worker.end());
        
        long long int sum=0;
        int m=worker.size();
        int j=n-1;
        for(int i=m-1;i>=0;i--){
             int d=v[j].first;
            
             if(worker[i]>=d){
                sum+=v[j].second;
             }
             else{
                while(v[j].first> worker[i]){
                    j-=1;
                    if(j==-1){
                        return sum;
                    }
                }
                sum+=v[j].second;
             }

        }

        return sum;
    }
};