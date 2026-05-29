class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=9999;
        for(int i=0;i<nums.size();i++){
             int num=nums[i];
             int sum=0;
             while(num!=0){
                 int r=num%10;
                 sum+=r;
                 num=num/10;
             }
             cout<<sum;
ans=min(ans,sum);
             cout<<"\n";
        }
        return ans;
    }
};