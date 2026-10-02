class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        vector<pair<int,int>> v=events;
        events.push_back({startTime,1});
        events.push_back({endTime,-1});
        int cnt=0;
        sort(events.begin(),events.end());
        for(auto x:events){
            cnt+=x.second;
            if(cnt>1){
                events=v;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */