class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        cout<<n;
        while(j<n){
            if(nums[j]==1){
                int sz=(j-i+1);
                ans=max(ans,sz);
                j+=1;
            }
            else{
                if(k>0){
                    k-=1;
                     int sz=(j-i+1);
                    ans=max(ans,sz);
                    j+=1;
                }
                else{
                    while(1){
                        if(nums[i]==0){
                            i+=1;
                           
                            break;
                        }

                        i+=1;
                    }
                    int sz=(j-i+1);
                    ans=max(ans,sz);
                    j+=1;
                }
            }
        }
        return ans;
    }
};