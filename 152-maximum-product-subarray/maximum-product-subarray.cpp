class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int ans=1;
        int t=0;
        long long int val=1;
        long long int res=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                t=0;
                if(res<0){
                    res=0;
                }
                ans=1;
                val=1;
            }
            else{
            ans=ans*nums[i];
            res=max(res,ans);
            if(ans<0){
                if(t==1){
                long long int temp=ans/val;
                res=max(res,temp);}
            }
            if(ans<0){
                 if(t==0){
                     val=ans;
                 }
                 t=1;
            }
            
            
            }
            
        }
        
        return res;
    }
};