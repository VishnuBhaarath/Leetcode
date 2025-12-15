class Solution {
public:
    long long minMoves(vector<int>& balance) {
      long long int sum=0;
     long long int idx=-1;
      long long int val=0;
      for(int i=0;i<balance.size();i++){
        sum+=balance[i];
        if(balance[i]<0){
            val=balance[i];
            idx=i;
    
        }
      }
      if(idx==-1){
        return 0;
      }
    
      if(sum<0){
        return -1;
      }

      long long int n=balance.size();
      long long int i=idx-1;
      long long int j=idx+1;
      if(idx==0){
         i=n-1;
      }
      if(idx==n-1){
        j=0;
      }
      long long int cnt=0;
      long long int t=1;
      cout<<val;

      while(val<0){
       
        if(balance[i]>=abs(val)){
            cnt+=(t*(-val));
            val=0;
            return cnt;
        }
        else{
            cnt+=(t*balance[i]);
            val+=balance[i];
        }
        
        if(balance[j]>=abs(val)){
            cnt+=(t*-val);
            val=0;
            return cnt;
        }
        else{
            cnt+=(t*balance[j]);
            val+=balance[j];
        }
        t+=1;
        i-=1;
        j+=1;
       
        if(j==n){
            j=0;
        }
        if(i==-1){
            i=n-1;
        }
      }
       return cnt;

    }
};