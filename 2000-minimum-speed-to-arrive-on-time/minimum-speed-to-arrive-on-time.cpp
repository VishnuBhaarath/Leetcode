class Solution {
public:
    double check(vector<int>& dist,int m){
        double time=0;
       
        for(int i=0;i<dist.size();i++){
            int val=dist[i]/m;
            
            int r=dist[i]%m;
            if(i==dist.size()-1){
              double val1=double(dist[i])/double(m);
           
              time+=val1;
              return time;
            }
            time+=val;
            if(r!=0){
                time+=1;
            }
        
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        double ans=-1;
        int l=1;
        int r=1e7;
        for(int i=0;i<dist.size();i++){
            if(dist[i]>r){
                r=dist[i];
            }
            if(dist[i]<l){
                l=dist[i];
            }
        }

        while(l<=r){
            int m=l+(r-l)/2;
           
            double time=check(dist,m);
          
          
            if(time>hour){
                l=m+1;
            }
            else{
                ans=m;
                r=m-1;
            }
        }
  return ans;
    }
};