class MinStack {
public:
    stack<pair<int,int>> s;
    stack<pair<int,int>> s1;
    int cnt=0;
    int cnt1=0;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push({val,cnt});
       
        if(s1.empty()){
            s1.push({val,cnt});
          
        }
        else if(val<=s1.top().first){
            s1.push({val,cnt});
        
        }
         cnt+=1;
    }
    
    void pop() {
        if(s1.top().second==s.top().second){
            s1.pop();
         
        }
        s.pop();
        cnt-=1;
    }
    
    int top() {
        int tp=s.top().first;
        return tp;
    }
    
    int getMin() {
        return s1.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */