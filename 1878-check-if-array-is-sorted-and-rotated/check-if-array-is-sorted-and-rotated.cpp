class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> v1=nums;
        for(int i=0;i<nums.size();i++){
            v1.push_back(nums[i]);
        }
        int n=v1.size()-1;
        int cnt=1;
        if(cnt==nums.size()){
            return true;
        }
        for(int i=0;i<n;i++){
             if(v1[i+1]>=v1[i]){
                cnt+=1;
             }
             else{
                cnt=1;
             }
             if(cnt==nums.size()){
                return true;
             }
        }
        
        return false;
    }
};