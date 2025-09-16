class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long int sum=nums[0];
        int i=1;
        long long int ans=1;
        long long int lt=1;
        long long int j=0;
        while(i<nums.size()){
           if((sum&nums[i])==0){
             sum=sum^nums[i];
             lt=(i-j)+1;
             ans=max(ans,lt);
             
           }
           else{
             while((sum&nums[i])!=0){
                sum=sum^nums[j];
                j+=1;
                if(j==i){
                    break;
                }
             }
             sum=sum|nums[i];
           }
           lt=i-j+1;
           ans=max(ans,lt);
           i+=1;

        }

       return ans;


    }
};