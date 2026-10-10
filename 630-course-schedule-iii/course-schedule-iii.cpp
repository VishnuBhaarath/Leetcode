class Solution {
public:

    int scheduleCourse(vector<vector<int>>& courses) {
        vector<vector<int>> v;
        for(int i=0;i<courses.size();i++){
            v.push_back({courses[i][1],courses[i][0]});
        }
        sort(v.begin(),v.end());
       
        int r=0;
        int cnt=0;
        priority_queue<int> pq;
        for(int i=0;i<v.size();i++){
             if((r+v[i][1])<= v[i][0]){
                    cnt+=1;
                    r+=v[i][1];
                    pq.push(v[i][1]);
             }
             else{
                 if(!pq.empty()){
                    int tp=pq.top();
                    if(v[i][1]<tp){
                    if((r-tp+v[i][1])<=v[i][0]){
                        pq.pop();
                        r+=v[i][1];
                        r-=tp;
                        pq.push(v[i][1]);
                    }
                    }
                 }
             }
           
        }
        return cnt;
    }
};