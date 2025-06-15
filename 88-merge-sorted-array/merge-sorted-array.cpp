class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=nums1.size()-1;

        int i=m-1;
        int k =n-1;
         while(i>=0 && k>=0){

            if(nums1[i]>nums2[k]){
                 nums1[j]=nums1[i];
                 i-=1;
            }
            else{
                 nums1[j]=nums2[k];
                 k-=1;
            }
            j-=1;
         }
         while(i>=0){
            nums1[j]=nums1[i];
            i-=1;
            j-=1;
         }
         while(k>=0){
            nums1[j]=nums2[k];
            j-=1;
            k-=1;
         }
    }
};
