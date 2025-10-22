class StockSpanner {
public:
    stack<int> s;
    vector<int> v;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        if(s.empty()){
            s.push(v.size()-1);
        }
        else{
            if(price<v[s.top()]){
                s.push(v.size()-1);
            }
            else{
                while(price>=v[s.top()]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(!s.empty()){
                    int ans=v.size()-1-s.top();
                      s.push(v.size()-1);
                    return ans;
                }
                else{
                       s.push(v.size()-1);
                    return v.size();
                }
            }
        }
        return 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */