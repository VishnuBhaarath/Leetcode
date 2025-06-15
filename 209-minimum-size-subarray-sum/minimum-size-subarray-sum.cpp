class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=-1;
        int sum=0;
        int j=0;
        int n=nums.size();
        int ans=-1;
        while(j<n){
            sum+=nums[j];
            if(sum>=target){
                int len=(j-i);
               
                if(ans==-1){
                    ans=len;
                }
                else{
                    ans=min(ans,len);
                }
                
                while(sum>=target){
                    i+=1;
                    sum-=nums[i];
                    if(sum>=target){
                    len=(j-i);
                    ans=min(ans,len);
                    
                    }

                }
            }
             j+=1;
        }
        
        ans=max(ans,0);
        return ans;
    }
};