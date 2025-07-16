class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> dp;
        int n=intervals.size();
        int i=0;
        int start=newInterval[0];
        int end=newInterval[1];
    
        if(intervals.size()==0){
            dp.push_back({start,end});
             return dp;
        }
       
        if(newInterval[1]<intervals[i][0]){
            dp.push_back({start,end});
            while(i<intervals.size()){
                dp.push_back({intervals[i][0],intervals[i][1]});
                i+=1;
            }
        }
        while(i<intervals.size()){
            if(intervals[i][1]<newInterval[0]){
                dp.push_back({intervals[i][0],intervals[i][1]});
            }
            else{
                 start=min(start,intervals[i][0]);
                 while(end>intervals[i][1]){
                    i+=1;
                    if(i>=intervals.size()){
                        break;
                    }
                    
                 }
                 if(i>=intervals.size()){
                    dp.push_back({start,end});
                    break;
                 }  
                 if(end<intervals[i][0]){
                    dp.push_back({start,end});
                 }
                 else{
                    dp.push_back({start,intervals[i][1]});
                    i+=1;
                 }
                break;
            }
            i+=1;
        }
      

        while(i<intervals.size()){
            dp.push_back({intervals[i][0],intervals[i][1]});
            i+=1;
        }
        if(newInterval[0]> intervals[n-1][1]){
            dp.push_back({newInterval[0],newInterval[1]});
        }
        return dp;
    }
};