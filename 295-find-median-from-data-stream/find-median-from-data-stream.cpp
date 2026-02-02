class MedianFinder {
public:
 
    multiset<int> s1;
    multiset<int> s2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s1.insert(num);
      
        auto tp1 = *s1.rbegin();
        s1.erase(s1.find(tp1));
        s2.insert(tp1);
     
     
        if(s2.size()>s1.size()){
            auto tp3=*s2.begin();
            s2.erase(s2.find(tp3));
            s1.insert(tp3);
        }
       
    }
    
    double findMedian() {
        int n=s2.size()+s1.size();
       
        if((n%2)==0){
           double val=(double)(*s1.rbegin()) + (double)(*s2.begin());
           return val/2;
        }
        else{
            double val=*s1.rbegin();
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