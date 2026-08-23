class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.empty()){
            pq.push(num);
        }
        else if(pq.top()<num){
            pq1.push(num);
            if(pq1.size()>pq.size()){
                int tp=pq1.top();
                pq1.pop();
                pq.push(tp);
            }
        }
        else{
            pq.push(num);
            if(pq.size()> pq1.size()+1){
                int tp=pq.top();
                pq.pop();
                pq1.push(tp);
            }
        }
   
        
    }
    
    double findMedian() {
        int sz=pq.size()+pq1.size();
       
        if(sz%2==0){
            return (double)((double)(pq.top())+ (double)(pq1.top()))/2.0;
        }
        else{
            return pq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */