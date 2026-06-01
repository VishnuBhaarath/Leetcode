class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());

        int n=cost.size();
        int i=0;
        int j=n-1;
int sum=0;
        while(j>=0){
            sum+=cost[j];
            j-=1;
            if(j>=0){
                sum+=cost[j];

            }
            j-=1;
            j-=1;
        }
        return sum;
    }
};