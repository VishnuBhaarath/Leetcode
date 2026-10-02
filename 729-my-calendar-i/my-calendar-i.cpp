class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto x:events){
            if(startTime<x.second && endTime>x.first){
                return false;
            }
        }
        events.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */