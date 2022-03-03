class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int diff=nums[1]-nums[0];
        int j=2;
        int i=0;
        int ans=0;
        while(j<n){
            int diff1=nums[j]-nums[j-1];
            if(diff==diff1){
                j+=1;
            }
            else{
                
                diff=diff1;
                int val=j-i-2;
                int sum=((val)*(val+1))/2;
                ans+=sum;
                i=j-1;
                j+=1;
            }
        }
      
            int val=j-i-2;
        if(val>0){
                int sum=((val)*(val+1))/2;
                ans+=sum;}
      
        return ans;
    }
};