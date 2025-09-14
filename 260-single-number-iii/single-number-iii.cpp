class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> v;
        int i=0;
        while((i)<n){
            if((i+1)<n){
            if(nums[i]==nums[i+1]){
                i+=2;
            }
            else{
               v.push_back(nums[i]);
               i+=1;
               if(v.size()==2){
                  return v;
               }
            }
            }
            else{
                v.push_back(nums[i]);
                return v;
            }
        }
        return v;
    }
};