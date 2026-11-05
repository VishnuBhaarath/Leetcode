class Solution {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq1;
    map<int,int> umap;
    int s1=0;
    int s2=0;
    vector<double> ans;
     void addNum(int num) {
         while(!pq1.empty() && umap[pq1.top()]>0){
             umap[pq1.top()]-=1;
             pq1.pop();
        }

         while(!pq.empty() && umap[pq.top()]>0){
             umap[pq.top()]-=1;
             pq.pop();
        }
        if(s1==0){
         pq.push(num);
         s1+=1;
        }
        else{
        if(s2==0){
             while(s1> (s2+1)){
                 int tp=pq.top();
                 pq.pop();
                 pq1.push(tp);

                 s1-=1;
                 s2+=1;
                 prune();
             }
             if(s2!=0){
                if(num>=pq1.top()){
                    pq1.push(num);
                    s2+=1;
                    if(s2>s1){
                        int tp=pq1.top();
                        pq1.pop();
                        pq.push(tp);
                        prune();
                        s2-=1;
                        s1+=1;
                    }
                }
                else{
                    pq.push(num);
                    s1+=1;
                    if(s1>(s2+1)){
                        int tp=pq.top();
                 pq.pop();
                 pq1.push(tp);
                 prune();
                 s1-=1;
                 s2+=1;
                    }
                }
             }
             else{
                pq.push(num);
                s1+=1;
                int tp=pq.top();
                pq.pop();
                prune();
                s1-=1;
                pq1.push(tp);
                s2+=1;
             }
        }
        else{
            if(num>=pq1.top()){
                pq1.push(num);
                s2+=1;
                 if(s2>s1){
                        int tp=pq1.top();
                        pq1.pop();
                        prune();
                        pq.push(tp);
                        s2-=1;
                        s1+=1;
                    }
            }
            else{
                 pq.push(num);
                 s1+=1;
                    if(s1>(s2+1)){
                        int tp=pq.top();
                 pq.pop();
                 pq1.push(tp);
                 prune();
                 s1-=1;
                 s2+=1;
            }
        }
        }
        }
    }

    void findMedian() {
      
        int sz=s1+s2;
        if(sz%2!=0){
            ans.push_back(pq.top());
        }
        else{
            double temp=(double)(pq.top())+(double)(pq1.top());
            temp/=2;
            ans.push_back(temp);
        }

       
       
      
        //return 2;
    }

    void prune(){
    while(!pq1.empty() && umap[pq1.top()]>0){
        umap[pq1.top()]-=1;
        pq1.pop();
    }
    while(!pq.empty() && umap[pq.top()]>0){
        umap[pq.top()]-=1;
        pq.pop();
    }
}

    void removeNum(int num){
        if(!pq1.empty() && num>=pq1.top()){
            s2-=1;
            umap[num]+=1;
        }
        else{
            s1-=1;
            umap[num]+=1;
        }
        while(!pq1.empty() && umap[pq1.top()]>0){
             umap[pq1.top()]-=1;
             pq1.pop();
        }

         while(!pq.empty() && umap[pq.top()]>0){
             umap[pq.top()]-=1;
             pq.pop();
        }


          if(s1>(s2+1)){
                        int tp=pq.top();
                 pq.pop();
                 pq1.push(tp);
                 s1-=1;
                 s2+=1;
            }

             if(s2>s1){
                        int tp=pq1.top();
                        pq1.pop();
                        pq.push(tp);
                        s2-=1;
                        s1+=1;
                    }

            
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<k;i++){
             addNum(nums[i]);
        }
        findMedian();
        int i=k;
        int j=0;
        while(i<n){
            removeNum(nums[j]);
            addNum(nums[i]);
            findMedian();
            i+=1;
            j+=1;
        }
        return ans;
      
    }
};