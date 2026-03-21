class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            vector<int> v=gas;
            vector<int> c=cost;

            for(int i=0;i<gas.size();i++){
                 v.push_back(gas[i]);
                 c.push_back(cost[i]);
            }
            
           

            int sum=v[0];
            int cnt=1;
            int idx=0;

            int i=1;
            while(i<v.size()){
                 if(sum>=c[i-1]){
                     sum+=v[i];
                     sum-=c[i-1];
                     cnt+=1;
                     if(cnt==gas.size()+1){
                        return idx;
                     }
                 }
                 else{
                      sum=v[i];
                      idx=i;
                      cnt=1;
                 }
                 i+=1;
            }


          return  -1;
    }
};