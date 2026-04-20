class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=n-1;
        int j=m-1;
        int ans=0;
        while(i>=0 && j>=0){
             if(i>=j){
                i=j;
             }
             if(nums1[i]<=nums2[j]){
                int dist=j-i;
                ans=max(ans,dist);
                i-=1;
             }
             else{
                 j-=1;
             }
        }
        return ans;
    }
};