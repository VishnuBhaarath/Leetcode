class Solution {
public:
    int check(int m,int n,int m1) {
        int cnt=0;
        for(int i=1;i<=m;i++){
            int val=m1/i;
            val=min(val,n);
            cnt+=val;
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
       
       
        int h=m*n;
        int l=1;


        int ans=-1;
        while(l<=h){
           int m1=l+(h-l)/2;
          
           int val= check(m,n,m1);
           cout<<l;
           cout<<" ";
           cout<<h;
           cout<<" ";
           cout<<m1;
           cout<<" ";
           cout<<val;
           cout<<"\n";
           if(val>=k){
            ans=m1;
            h=m1-1;
           }
           else if(val<k){
            l=m1+1;
           }
   
        }
        return ans;

    }
};