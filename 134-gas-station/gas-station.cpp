class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int val=0;
        int n=gas.size();
        for(int i=0;i<gas.size();i++){
            val+=gas[i]-cost[i];
        }
        if(val<0){
            return -1;
        }
        vector<int> v1=gas;
        vector<int> v2=cost;

        for(int i=0;i<gas.size();i++){
            v1.push_back(gas[i]);
            v2.push_back(cost[i]);
        }
        int st=-1;
        int sum=0;

        for(int i=0;i<v1.size();i++){
             if(st==-1){
                 if(v1[i]>=v2[i]){
                    sum+=(v1[i]-v2[i]);
                    st=i;
                 }
             }
             else{
                if((sum+v1[i])>=v2[i]){
                    sum+=v1[i];
                    sum-=v2[i];
                    if((i-st+1)==n){
                        return st;
                    }
                }
                else{
                    st=-1;
                    sum=0;
                }
             }
        }
        return st;
    }
};