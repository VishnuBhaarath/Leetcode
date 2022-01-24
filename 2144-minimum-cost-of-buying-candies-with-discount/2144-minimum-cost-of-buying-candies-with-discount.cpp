class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int i=n-1;
        int sum=0;
        while(i>=0){
            sum+=cost[i];
            i-=1;
            if(i>=0){
                sum+=cost[i];
            }
            i-=2;
        }
        return sum;
    }
};