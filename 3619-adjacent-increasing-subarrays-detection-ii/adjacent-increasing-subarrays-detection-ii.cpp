class Solution {
public:
    bool func(int m,vector<int> nums){
        int n=nums.size();
        int cnt1=1;
        int cnt2=0;
        int i=1;
        while(i<nums.size()){
             if(cnt2==0){
                if(nums[i]>nums[i-1]){
                    cnt1+=1;
                }
                else{
                    if(cnt1>=m){
                    cnt2=1;}
                    else{
                        cnt1=1;
                    }
                }
             }
             else{
                 if(nums[i]>nums[i-1]){
                    cnt2+=1;
                 }
                 else{
                    cnt1=1;
                    cnt2=0;
                 }
             }

             if(cnt1 >= (2*m)){
                return true;
             }
             if(cnt1>=m && cnt2>=m){
                return true;
             }

             i+=1;
        }

        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();

        int l=0;
        int r=n-1;
        int ans=1;
        while(l<=r){
            int m=l+(r-l)/2;

            if(func(m,nums)){
                ans=m;
                l=m+1;
            } 
            else{
                r=m-1;
            }

        }
        return ans;
    }
};