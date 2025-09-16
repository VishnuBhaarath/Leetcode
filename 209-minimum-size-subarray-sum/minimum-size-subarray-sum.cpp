class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        long long int sum=0;
        long long int ans=0;
        while(i<nums.size()){
             sum+=nums[i];
             
                long long int lt=i-j+1;
                if(sum>=target){
                if(ans==0){
                    ans=lt;
                }
                else{
                    ans=min(ans,lt);
                }
                }
                while(sum>=target){
                    sum-=nums[j];
                    j+=1;
                    if(sum>=target){
                    lt=i-j+1;
                    ans=min(ans,lt);}
                    if(j==i){
                        break;
                    }
                }

            
            i+=1;
        }
        while(sum>=target){
            sum-=nums[j];
            j+=1;
             if(sum>=target){
                    long long int lt=i-j+1;
                    ans=min(ans,lt);}
            if(j==nums.size()){
                break;
            }        
        }

        return ans;

    }
};