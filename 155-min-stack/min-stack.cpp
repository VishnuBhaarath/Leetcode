class MinStack {
public:
    stack<pair<int,int>> s;
    stack<pair<int,int>> s1;
    int idx=0;

    MinStack() {
        
    }
    
    void push(int value) {
        s.push({idx,value});
        if(s1.empty()){
            s1.push({idx,value});
        }
        else if(s1.top().second>=value){
            s1.push({idx,value});
        }
        idx+=1;
    }
    
    void pop() {
        int idx=s.top().first;
        s.pop();
        while(s1.top().first>=idx){
            s1.pop();
            if(s1.empty()){
                break;
            }
        }
    }
    
    int top() {
        return s.top().second;
    }
    
    int getMin() {
        return s1.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */