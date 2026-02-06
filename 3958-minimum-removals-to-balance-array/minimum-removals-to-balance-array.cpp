class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int n=nums.size();
        long long int ans=-1;
        for(int i=0;i<nums.size();i++){
             long long int l=i;
             long long int r=n-1;
             long long int idx=-1;
             while(l<=r){
               long long int m=l+(r-l)/2;
             
                long long int val=nums[m];
                if(val>((long long int)(k)*(long long int)(nums[i]))){
                    r=m-1;
                    idx=m;
                }
                else{
                    l=m+1;
                }
             }
          

             long long int val=0;
             if(idx==-1){
                 val=i;
                 
             }
             else{
                val=n-idx;
                val+=i;

             }
             if(ans==-1){
                ans=val;
             }
             else{
                ans=min(ans,val);
             }
             
        }
        return ans;
    }
};