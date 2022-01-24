class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int min1=100001;
        long long int max1=-100001;
        long long int sum=0;
        for(int i=0;i<differences.size();i++){
            sum+=differences[i];
            if(sum<min1){
                min1=sum;
            }
            if(sum>max1){
                max1=sum;
            }
        }
      
        long long int val1=lower-min1;
        long long int val2=upper-max1;
        val1=max(val1,(long long int)lower);
        val2=min(val2,(long long int)upper);
        
        int ans=val2-val1+1;
        if(ans<0){
            return 0;
        }
        return ans;
    }
};