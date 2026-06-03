class Solution {
public:
    int func(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){
        int end=-1;
        for(int i=0;i<landStartTime.size();i++){
            int val=landStartTime[i]+landDuration[i];
            if(end==-1){
                end=val;
            }
            end=min(end,val);
        }
        cout<<end;
        cout<<"\n";
        int end1=-1;
        for(int i=0;i<waterDuration.size();i++){
            if(end1==-1){
                end1=max(end,waterStartTime[i])+waterDuration[i];
            }
           end1=min(end1,max(end,waterStartTime[i])+waterDuration[i]);
        }
         return end1;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int val= func(landStartTime,landDuration,waterStartTime,waterDuration);
        int val1=func(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(val,val1);


    }
};