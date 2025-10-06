class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int idx=-1;
        vector<int> v;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
               if(idx==-1){
                 idx=mid;
               }
               idx=min(idx,mid);
               r=mid-1;
            }
        }
        v.push_back(idx);
        if(idx==-1){
            v.push_back(idx);
            return v;
        }
        idx=-1;
        l=0;
        r=n-1;
         while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target){
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
               if(idx==-1){
                 idx=mid;
               }
               idx=max(idx,mid);
               l=mid+1;
            }
        }
        v.push_back(idx);
        return v;

    }
};