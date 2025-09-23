class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> umap;
        for(int i=0;i<nums4.size();i++){
            for(int j=0;j<nums3.size();j++){
            umap[nums4[i]+nums3[j]]+=1;
            }
        }
        long long int cnt=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
               
                    int val=nums1[i]+nums2[j];
                    if(umap[-val]>0){
                        cnt+=umap[-val];
                    }
                
            }
        }
        return cnt;
    }
};