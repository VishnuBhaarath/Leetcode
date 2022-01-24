class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
            
        }
        int idx=0;
        for(int i=0;i<pos.size();i++){
            nums[idx]=pos[i];
            nums[idx+1]=neg[i];
            idx+=2;
        }
        return nums;
    }
};