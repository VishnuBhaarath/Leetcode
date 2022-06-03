class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long int sum1=0;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            sum1+=nums[i];
            sum-=nums[i];
            
            if(sum1>=sum){
                cnt+=1;
            }
        }
        return cnt;
    }
};