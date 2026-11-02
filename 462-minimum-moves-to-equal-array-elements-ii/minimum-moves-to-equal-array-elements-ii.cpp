class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long int l=0;
        int n=nums.size();
        long long int r=n-1;
        long long int ans=INT_MAX;
        while(l<=r){
            long long int m=l+(r-l)/2;

            long long int sum1=0;
            long long int sum2=0;
            for(int j=m+1;j<n;j++){
                sum1+=abs(nums[j]-nums[m]);
            }
            for(int j=m-1;j>=0;j--){
                sum2+=abs(nums[j]-nums[m]);
            }
            ans=min(ans,sum1+sum2);
            if(sum1>=sum2){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        
        return ans;


    }
};