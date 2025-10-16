class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i+1){
                continue;
            }
            else if(nums[i]>n || nums[i]<=0){
                continue;
            }
            else{
                int j=nums[i];
                if(nums[j-1]==j){
                    continue;
                }
                else{
                    while(1){
                        int idx=nums[i];
                        idx-=1;
                        if(idx<nums.size() && idx>=0){
                        if(nums[idx]!=nums[i]){
                            int temp=nums[idx];
                            nums[idx]=nums[i];
                            nums[i]=temp;
                        }
                        else{
                            break;
                        }}
                        else{
                            break;
                        }
                    }
                }
            }
        }
         for(int i=0;i<nums.size();i++){
            if(nums[i]!=(i+1)){
                return (i+1);
            }
         }
         cout<<"\n";
         return n+1;
    }
};