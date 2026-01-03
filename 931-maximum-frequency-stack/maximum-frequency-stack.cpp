class FreqStack {
public:
    map<int,int> umap;
    priority_queue<pair<int,pair<int,int>>> pq;
    int idx=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        umap[val]+=1;
        pq.push({umap[val],{idx,val}});
        idx+=1;
        
    }
    
    int pop() {
        pair<int,int> p=pq.top().second;

        pq.pop();
        umap[p.second]-=1;
        return p.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */