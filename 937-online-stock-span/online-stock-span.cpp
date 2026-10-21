class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty()){
            s.push({price,1});
            return 1;
        }
        else{
            if(s.top().first> price){
                s.push({price,1});
                return 1;
            }
            else{
                int cnt=0;
                while(s.top().first<=price){
                    cnt+=s.top().second;
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                s.push({price,cnt+1});
            }
        }
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */