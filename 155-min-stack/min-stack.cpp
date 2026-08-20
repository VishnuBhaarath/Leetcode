class MinStack {
public:
    //stack<int> s;
    //stack<int> s1;
    unordered_map<int,int> umap;
    stack<pair<int,int>> s;
    stack<pair<int,int>> s1;
   
    int idx=0;
    MinStack() {
        
    }
    
    void push(int value) {
       
       
        if(s1.empty()){
            s1.push({idx,value});
        }
        else{
            int tp=s1.top().second;
            if(tp>value){
                s1.push({idx,value});
            }
        }
         s.push({idx,value});
          umap[idx]=value;
        idx+=1;
    }
    
    void pop() {
         int tp=s.top().first;;
          s.pop();
          if(s1.size()>0){
        while(s1.top().first>=tp){
            s1.pop();
            if(s1.empty()){
                break;
            }
        }}
       
    }
    
    int top() {
        int tp=s.top().second;
       
        return tp;
    }
    
    int getMin() {
        int tp=s.top().first;
      
        while(s1.top().first>tp){
            s1.pop();
        }
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