class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp;
        for(int i=0;i<nums.size();i++){
           if(i>0 && nums[i]==nums[i-1]){
            continue;
           }
           if(nums[i]>0){
            break;
           }
           int j=i+1;
           int k=n-1;
           while(j<k){
              int sum=nums[i]+nums[j]+nums[k];
              if(sum>0){
                k-=1;
              }
              else if(sum<0){
                j+=1;
              }
              else{
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                dp.push_back(v);
                j+=1;
                k-=1;
                while(j<k && nums[j]==nums[j-1]) j+=1;
                while(j<k && nums[k]==nums[k+1]) k-=1;
               
              }
           }
        }
        return dp;
    }
};