class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        int tp=pq.top();
        pq.pop();
        pq1.push(tp);
        if(pq1.size() > pq.size()){
            int tp1=pq1.top();
            pq1.pop();
            pq.push(tp1);
        }
    }
    
    double findMedian() {
        int n=pq.size()+pq1.size();
       
        if((n%2)==0){
           double val=(double)(pq.top()) + (double)(pq1.top());
           return val/2;
        }
        else{
            double val=pq.top();
            return val;
        }
        return 10;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */