class NumArray {
public:
    vector<int> psum;
    NumArray(vector<int>& nums) {
       psum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            int temp=psum[psum.size()-1];
            temp+=nums[i];
            psum.push_back(temp);
        }
        for(int i=0;i<psum.size();i++){
            cout<<psum[i];
            cout<<" ";
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return psum[right];
        }
        return psum[right]-psum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */