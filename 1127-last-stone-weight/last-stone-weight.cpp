class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(!pq.empty()){
            int tp=pq.top();
            pq.pop();
            if(!pq.empty()){
                int tp1=pq.top();
                pq.pop();
                if(tp!=tp1){
                pq.push(tp-tp1);
            }
            else{
                pq.push(0);
            }
            }
            else{
                return tp;
            }
            

        }
        return -1;
    }
    
};