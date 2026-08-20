class MinStack {
public:
    stack<int> s;
    stack<int> s1;
    map<int,int> umap;
    int idx=0;
    MinStack() {
        
    }
    
    void push(int value) {
       
       
        if(s1.empty()){
            s1.push(idx);
        }
        else{
            int tp=umap[s1.top()];
            if(tp>value){
                s1.push(idx);
            }
        }
         s.push(idx);
          umap[idx]=value;
        idx+=1;
    }
    
    void pop() {
         int tp=s.top();
          s.pop();
          if(s1.size()>0){
        while(s1.top()>=tp){
            s1.pop();
            if(s1.empty()){
                break;
            }
        }}
       
    }
    
    int top() {
        int tp=s.top();
       
        return umap[tp];
    }
    
    int getMin() {
        int tp=s.top();
      
        while(s1.top()>tp){
            s1.pop();
        }
        return umap[s1.top()];
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