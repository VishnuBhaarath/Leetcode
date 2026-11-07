class Solution {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> pq1;
    int sz=0;
    int sz1=0;
    map<int,int> umap;

    void add(int num,int k){
        prune();
        if(!pq.empty()){
            if(pq.top()>=num){
                pq.push(num);
                sz+=1;
            }
            else{
                pq1.push(num);
                sz1+=1;
            }
        }
        else{
             pq1.push(num);
             sz1+=1;
        }
        prune();
        while(sz>k){
            int tp=pq.top();
            pq.pop();
            prune();
            pq1.push(tp);
            sz-=1;
            sz1+=1;
        }
        while(sz<k){
             if(!pq1.empty()){
                int tp=pq1.top();
                pq1.pop();
                prune();
                pq.push(tp);
                sz1-=1;
                sz+=1;
             }
             else{
                break;
             }
        }
        
    }

    void remove(int num,int k){
        umap[num]+=1;
        if(!pq.empty() && num<=pq.top()){
            sz-=1;
        }
        else{
            sz1-=1;
            sz1=min(sz1,0);
        }
        prune();
         while(sz>k){
            int tp=pq.top();
            pq.pop();
            prune();
            pq1.push(tp);
            sz-=1;
            sz1+=1;
        }
        while(sz<k){
             if(!pq1.empty()){
                int tp=pq1.top();
                pq1.pop();
                prune();
                pq.push(tp);
                sz1-=1;
                sz+=1;
             }
             else{
                break;
             }
        }
       

    }

    void prune(){
         while(!pq.empty() && umap[pq.top()]>0){
            umap[pq.top()]-=1;
            pq.pop();
         }
         while(!pq1.empty() && umap[pq1.top()]>0){
            umap[pq1.top()]-=1;
            pq1.pop();
         }
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<k;i++){
            if(nums[i]<0){
                pq.push(nums[i]);
                sz+=1;
            }
        }
        while(pq.size()>x){
            int tp=pq.top();
            pq.pop();
            sz-=1;
            sz1+=1;
            pq1.push(tp);
        }
        if(pq.size()==x){
            ans.push_back(pq.top());
        }
        else{
            ans.push_back(0);
        }

        

        int i=0;
        int j=k;
        while(j<n){
            if(nums[i]<0)
             remove(nums[i],x);
            if(nums[j]<0){
                add(nums[j],x);

            }
           
            if(sz==x){
                ans.push_back(pq.top());
            }
            else{
                ans.push_back(0);
            }
            i+=1;
            j+=1;
        }
        return ans;
    }
};