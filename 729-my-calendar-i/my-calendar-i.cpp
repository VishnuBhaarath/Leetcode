class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto it: s){
            if(startTime < it.second && endTime > it.first){
                return false;
            }
          
        }
        s.insert({startTime,endTime});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */