class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int cnt=0;
        stack<int> s;
        for(int i=0;i<weight.size();i++){
            if(s.empty()){
                s.push(weight[i]);
            }
            else if(weight[i]>=s.top()){
                s.push(weight[i]);
            }
            else{
                cnt+=1;
                while(!s.empty()){
                    s.pop();
                }
            }
        }
        return cnt;
    }
};