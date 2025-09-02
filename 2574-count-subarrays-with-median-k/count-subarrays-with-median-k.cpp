class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k){
                j=i;
            }
            if(nums[i]>k){
                nums[i]=1;
            }
            else if(nums[i]==k){
                nums[i]=0;
            }
            else{
                nums[i]=-1;
            }
        }
       
        int i=j;
        map<int,int> umap;
        int sum=0;
        int ans=0;
        while(i<nums.size()){
            sum+=nums[i];
            if(sum==0 || sum==1){
                ans+=1;
            }
            umap[sum]+=1;
            i+=1;
        }
         
        i=j-1;
      
        sum=0;
 
        while(i>=0){
         sum+=nums[i];
         if(sum==0 || sum==1){
            ans+=1;
         }
         ans+=umap[-sum];
         if(sum==0){
            ans-=1;
         }
         if(sum>0){
            int val=sum-1;
            ans+=umap[-val];
            if(val==0){
                ans-=1;
            }
         }
         else if(sum<0){
            int val=abs(sum);
            val+=1;
            ans+=umap[val];
         }
         else if(sum==0){
            ans+=umap[1];
         }
         
         i-=1;
       
        }

       
         return ans;
    }
};