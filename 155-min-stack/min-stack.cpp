class MinStack {
public:
    stack<int> s;
    stack<int> s1;
    map<int,int> umap;
    int cnt=0;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s1.push(cnt);
        }
        else if(val<=umap[s1.top()]){
            s1.push(cnt);
        }
        s.push(cnt);
        umap[cnt]=val;
        cnt+=1;
    }
    
    void pop() {
        if(s.top()==s1.top()){
            s1.pop();
        }
        s.pop();
    }
    
    int top() {
        return umap[s.top()];
    }
    
    int getMin() {
        return umap[s1.top()];
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