class Solution {
public:
    int addDigits(int num) {
        int n=num;
        if((n/10)==0){
            return n;
        }
        int sum=0;
        while(n){
            int val=0;
            while(n){
                int r=n%10;
                n=n/10;
                val+=r;
            }
            n=val;
            
            sum+=val;
            if((n/10)==0){
                return n;
            }
        }
        cout<<sum;
        return 0;
    }
};