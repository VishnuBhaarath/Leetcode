class StockSpanner {
public:
    stack<int> s;
    vector<int> v;
    int idx=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int val=0;
        if(s.empty()){
            s.push(idx);
            val=1;
        }
        else if(price<v[s.top()]){
         
            val=(idx-s.top());
               s.push(idx);
         
        }
        else {
            while(price>=v[s.top()]){
                s.pop();
                if(s.empty()){
                    break;
                }
            }
            if(s.empty()){
                val=idx+1;
            }
            else{
                val=idx-s.top();
            }
            s.push(idx);
        }
        idx+=1;
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */