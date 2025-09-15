class Solution {
public:
long long int previousPowerOfTwo(long long int n) {
    if (n < 1) return 0;

    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    n |= (n >> 32);

    return n - (n >> 1);
}
    int rangeBitwiseAnd(int left, int right) {
        if(left==right){
            return left;
         }
        long long int l=previousPowerOfTwo(left);
        long long int r=previousPowerOfTwo(right);
      
        if(l!=r){
            return 0;
        }
        long long int ans=left;
        long long int sum=0;
        for(int i=31;i>=0;i--){
            cout<<i;
            cout<<" ";
            cout<<(left&(1<<i));
            cout<<" ";
            cout<<(right&(1<<i));
            if((left&(1<<i))==(right&(1<<i))){
                sum+=(left&(1<<i));
            }
            else{
                return sum;
            }
           
        }
        for(long long int i=left+1;i<=right;i++){
           

            ans=ans&i;

        }
        return ans;
    }
};