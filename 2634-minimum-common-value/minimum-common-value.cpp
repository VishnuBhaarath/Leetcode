class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        int i=0;
        int j=0;

        while(i<nums1.size() && j<nums2.size()){
             if(nums1[i]==nums2[j]){
                return nums1[i];
             }
             if(nums1[i]<nums2[j]){
                i+=1;
             }
             else{
                j+=1;
             }
        }
        return -1;
    }
};