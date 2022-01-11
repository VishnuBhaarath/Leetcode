class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt+=1;
            }
        }
        if(cnt==0){
            return 0;
        }
        int i=0;
        int j=0;
        int n=nums.size();
        int val=0;
        int ans=-1;
        while(j<n){
            if(nums[j]==0){
                val+=1;
            }
            j+=1;
            if((j-i)==cnt){
                if(ans==-1){
                    ans=val;
                }
                if(val<ans){
                    ans=val;
                }
                   cout<<val;
                if(nums[i]==0){
                    val-=1;
                }
                i+=1;
             
            }
        }
       
        j=0;
        while(i<n){
            if(nums[j]==0){
                val+=1;
            }
          
            ans=min(ans,val);
            if(nums[i]==0){
                val-=1;
            }
            i+=1;
            
            j+=1;
        }
        return ans;
    }
};