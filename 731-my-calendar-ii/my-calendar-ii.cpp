class MyCalendarTwo {
public:
    map<int,int> events;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        
        events[startTime]++;
        events[endTime]--;
        int cnt=0;
        for(auto x:events){
             cnt+=x.second;
             if(cnt>2){
                events[startTime]--;
                events[endTime]++;
                if(events[startTime]==0){
                    events.erase(startTime);
                }
                if(events[endTime]==0){
                    events.erase(endTime);
                }
                return false;
             }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */