class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        int j=1;
        int cnt=1;
        while(j<n){
            if(nums[j]==nums[j-1]){

            }
            else{
                nums[i]=nums[j];
                i+=1;
                cnt+=1;
            }
            j+=1;
        }

        return cnt;
    }
};