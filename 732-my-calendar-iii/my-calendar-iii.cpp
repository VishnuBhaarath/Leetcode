class MyCalendarThree {
public:
   map<int,int> umap;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        umap[startTime]+=1;
        umap[endTime]-=1;
        int cnt=0;
        int ans=1;
        for(auto x:umap){
            cnt+=x.second;
            ans=max(ans,cnt);
        }
        return ans;

    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */