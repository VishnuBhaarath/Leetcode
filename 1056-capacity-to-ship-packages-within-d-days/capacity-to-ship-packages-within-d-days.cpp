class Solution {
public:
    int func(vector<int> &weights,int m,int days){
        int sum=0;
        int i=0;
        int cnt=1;
      
        while(i< weights.size()){
            if(weights[i]>m){
                return -1;
            }
          
           

            if((sum+weights[i])<=m){
                 sum+=weights[i];
            }
            else{
                  cnt+=1;
                  if(cnt>days){
                   
                    return -1;
                  }
                  sum=weights[i];
            }
          
            i+=1;
        }
    
        return cnt;

    }
    int shipWithinDays(vector<int>& weights, int days) {
       
        int r=0;
        int l=0;
        for(int i=0;i<weights.size();i++){
            r+=weights[i];
            l=max(l,weights[i]);
           
        }
        int ans=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int val=func(weights,m,days);
            if(val==-1){
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