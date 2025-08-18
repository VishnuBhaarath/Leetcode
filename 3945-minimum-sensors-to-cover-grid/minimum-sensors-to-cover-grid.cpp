class Solution {
public:
    int minSensors(int n, int m, int k) {
        int a=2*k+1;
        int temp1=n/a;
        if(n%a!=0){
            temp1+=1;
        }
        int temp2=m/a;
        if(m%a!=0){
            temp2+=1;
        }
        int ans=temp1*temp2;
      
        return ans;

    }
};