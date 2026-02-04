class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<pair<int,int>> pq1;

        for(int i=0;i<capital.size();i++){
            pq.push({capital[i],profits[i]});
        }
        int sum=0;
        for(int i=0;i<k;i++){
            while(!pq.empty()){
                 if(pq.top().first<=w){
                    pq1.push({pq.top().second,pq.top().first});
                     pq.pop();
                 }
                 else{
                    break;
                 }
                
            }
            if(pq1.empty()){
                return w;
            }
            sum+=pq1.top().first;
            w+=pq1.top().first;
            pq1.pop();



        }

       return w;

    }
};