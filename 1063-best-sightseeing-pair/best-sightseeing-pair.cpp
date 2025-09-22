class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        long long int ans=0;
        for(int i=1;i<values.size();i++){
            long long int val=values[i]+values[i-1]-1;
            ans=max(ans,val);
            if((values[i-1]-1)>values[i]){
                values[i]=values[i-1]-1;
            }
        }
        return ans;
    }
};