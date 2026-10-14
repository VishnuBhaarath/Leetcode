class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        int m=(k*2);
        m-=2;
        priority_queue<int> pq;
        priority_queue<int,vector<int>,greater<int>> pq1;
        for(int i=1;i<n;i++){
            pq.push(weights[i]+weights[i-1]);
            pq1.push(weights[i]+weights[i-1]);
        }

        long long sum1=0;
        long long sum2=0;
        m=m/2;
        int i=0;
        while(i<m){
            sum1+=pq.top();
            sum2+=pq1.top();
            pq.pop();
            pq1.pop();
            i+=1;
        }

 

        return (sum1-sum2);
    }
};