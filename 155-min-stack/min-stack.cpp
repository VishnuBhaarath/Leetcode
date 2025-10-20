class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
       
    }
     stack<int>s1;
        stack<int> min;
    void push(int x) {
       s1.push(x);
       if(!min.empty()){
           int y=min.top();
           if(y<x){
               min.push(y);
           }
           else{
               min.push(x);
           }
       }
        else{
            min.push(x);
        }
    }
    
    void pop() {
       s1.pop();
        min.pop();
    }
    
    int top() {
       
        return s1.top();
    }
    
    int getMin() {
      
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */