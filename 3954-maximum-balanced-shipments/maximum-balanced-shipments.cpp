class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt=0;
        stack<int> s;
        int prev=-1;
        for(int i=0;i<weight.size();i++){
            if(prev==-1){
              prev=weight[i];
            }
            else if(weight[i]>=prev){
                prev=weight[i];
            }
            else{
                cnt+=1;
                prev=-1;
            }
        }
        return cnt;
    }
};