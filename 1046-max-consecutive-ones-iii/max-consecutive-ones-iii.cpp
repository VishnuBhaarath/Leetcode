class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        int j=0;
        int cnt=0;
     
        while(j<nums.size()){
            if(nums[j]==1){
                //j+=1;
                cnt=(j-i)+1;
                ans=max(ans,cnt);
            }
            else{
                if(k>0){
                   //  j+=1;
                     k-=1;
                }
                else{
                    while(nums[i]==1){
                        i+=1;
                    }
                    i+=1;
                  //  k+=1;
                   // j+=1;
                }
                cnt=(j-i)+1;
                 ans=max(ans,cnt);
            }
            
            j+=1;
        }
        return ans;
    }
};