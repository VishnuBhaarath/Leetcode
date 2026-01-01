class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n=temperatures.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push(i);
            }
            else{
                while(temperatures[i]>temperatures[s.top()]){
                    v[s.top()]=i-s.top();
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                s.push(i);
            }
        }
        return v;
    }
};