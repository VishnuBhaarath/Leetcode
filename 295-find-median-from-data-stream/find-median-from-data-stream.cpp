class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        pq1.push(pq.top());
        pq.pop();
        if(pq1.size()>pq.size()){
            pq.push(pq1.top());
            pq1.pop();
        }
    }
    
    double findMedian() {
        int sz=pq.size()+pq1.size();
        if(sz%2==0){
            double num1=pq1.top();
            double num2=pq.top();
            return (num1+num2)/2;
        }
        return pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */