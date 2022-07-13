class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    map<int,int> umap;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            pq.push(i);
            umap[i]+=1;
        }
    }
    
    int popSmallest() {
        if(!pq.empty()){
        int val=pq.top();
        pq.pop();
        umap[val]=0;
        return val;}
        return 0;
    }
    
    void addBack(int num) {
        if(umap[num]==0){
            pq.push(num);
            umap[num]+=1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */