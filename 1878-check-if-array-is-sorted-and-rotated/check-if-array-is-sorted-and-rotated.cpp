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
        int j=0;
        int i=0;
        while(j<(2*nums.size())){
             if(nums[i+1]>=nums[i]){
                cnt+=1;
             }
             else{
                cnt=1;
             }
             i+=1;
             j+=1;
             if(cnt==nums.size()){
                return true;
             }
             if(i==nums.size()-1){
                if(nums[0]>=nums[i]){
                    cnt+=1;
                }
                else{
                    cnt=1;
                }
                i=0;
             }
             if(cnt==nums.size()){
                return true;
             }
        }
        
        
        return false;
    }
};