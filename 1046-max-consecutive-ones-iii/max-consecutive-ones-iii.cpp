class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        while(j<nums.size()){
          
            if(nums[j]==1){
                cnt+=1;
            }
            else{
                if(k>0){
                   
                    k-=1;
                    cnt+=1;
                }
                else{
                    while(nums[i]!=0){
                        i+=1;
                        cnt-=1;
                        
                    }
                  
                    i+=1;
                    cnt-=1;
                    k+=1;
                    cnt+=1;
                    k-=1;
                    

                }
            }
          
            ans=max(ans,cnt);
            j+=1;
        }
        return ans;
    }
};