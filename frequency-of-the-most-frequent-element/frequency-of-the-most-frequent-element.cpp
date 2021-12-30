class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
   int res = 1;
    sort(begin(nums), end(nums));
        int j=nums.size()-1;
        for(int i=nums.size()-1;i>0;i--){
            
            while(j>=0){
                if(nums[i]-nums[j]<=k){
                    k-=nums[i]-nums[j];
                }
                else{
                    break;
                }
                j-=1;
            }
            res=max(res,i-j);
            k+=(nums[i]-nums[i-1])*(i-j-1);
        }
    return res;}
};