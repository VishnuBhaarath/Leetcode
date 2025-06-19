class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1=0;
        for(int i=0;i<gas.size();i++){
            gas[i]=gas[i]-cost[i];
            sum1+=gas[i];
        }
       
        if(sum1<0){
            return -1;
        }
        int idx=-1;
        int sum=0;
    
        for(int i=0;i<gas.size();i++){
          
             if(gas[i]>=0){
                if(sum<0){
                idx=i;
                sum=gas[i];}
                else{
                    sum+=gas[i];
                    if(idx==-1){
                        idx=i;
                    }
                }
             }
             else{
                sum+=gas[i];
                if(sum<0){
                    idx=-1;
                }
             }
        }
        return idx;
    }
};