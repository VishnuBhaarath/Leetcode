class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long int cnt=0;
        map<long long,long long> umap;
        for(int i=0;i<tasks.size();i++){
            if(umap[tasks[i]]==0){
                cnt+=1;
                umap[tasks[i]]=cnt;
            }
            else{
                int val=umap[tasks[i]];
                int diff=cnt-val;
                if(diff>space){
                    cnt+=1;
                    umap[tasks[i]]=cnt;
                }
                else{
                    cnt+=(space-diff+1);
                    umap[tasks[i]]=cnt;
                }
            }
           
        }
        
        return cnt;
    }
};