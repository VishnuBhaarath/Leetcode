class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(int i=0;i<tasks.size();i++){
            v[tasks[i]-'A']+=1;
        }
        priority_queue<int> pq;
        for(int i=0;i<v.size();i++){
           
            if(v[i]!=0)
            pq.push(v[i]);
        }
        int cnt=0;
        while(!pq.empty()){
             vector<int> v1;
             cnt+=1;
             int tp=pq.top();
             pq.pop();
             tp-=1;
             
             int t=0;
             if(tp!=0){
                v1.push_back(tp);
             }
             else{
                t=1;
             }
             for(int i=0;i<n;i++){
                if(pq.empty()){
                    if(t==1){
                        break;
                    }
                    cnt+=(n-i);
                    break;
                }
                int tp1=pq.top();
                pq.pop();
                tp1-=1;
                if(tp1!=0){
                    v1.push_back(tp1);
                }
                cnt+=1;
                
             }
             
             for(int i=0;i<v1.size();i++){
                pq.push(v1[i]);
             }
        }
        return cnt;
    }
};