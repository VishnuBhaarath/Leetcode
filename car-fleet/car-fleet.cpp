class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int> umap;
        for(int i=0;i<position.size();i++){
            umap[position[i]]=speed[i];
        }
        sort(position.begin(),position.end());
        int n=position.size();
        int prev=position[n-1];
        vector<int> v;
        int t=0;
        int cnt=0;
        int sum=0;
        for(int i=n-2;i>=0;i--){
         
            if(t==0){
                int speed1=umap[position[i+1]];
                int speed2=umap[position[i]];
                double dist1=target-position[i+1];
                double dist2=target-position[i];
                double t1=dist1/speed1;
                double t2=dist2/speed2;
               
                if(t2<=t1){
                    t=1;
                    prev=position[i+1];
                    cnt+=2;
              }
               
            }
            else{
                int speed1=umap[prev];
                int speed2=umap[position[i]];
                double dist1=target-prev;
                double dist2=target-position[i];
                double t1=dist1/speed1;
                double t2=dist2/speed2;
              
                if(t2<=t1){
                    cnt+=1;
                }
                else{
                    t=0;
                    v.push_back(cnt);
                    sum+=cnt;
                    cnt=0;
                }
            }
        
        }
        if(cnt!=0){
            v.push_back(cnt);
            sum+=cnt;
        }
     
        int ans=n-sum+v.size();
        return ans;
    }
};