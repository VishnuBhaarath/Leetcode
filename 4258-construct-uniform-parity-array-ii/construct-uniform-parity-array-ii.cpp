class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
           int odd=-1;
           int even=-1;
           for(int i=0;i<nums1.size();i++){
              if(nums1[i]%2!=0){
                 if(odd==-1){
                    odd=nums1[i];
                 }
                 else{
                    odd=min(odd,nums1[i]);
                 }
              }
              else{
                 if(even==-1){
                    even=nums1[i];
                 }
                 else{
                    even=min(even,nums1[i]);
                 }
              }
           }
           if(odd==-1 || even==-1){
            return true;
           }
            int t=0;
            int s=0;
            int cnt=0;
            int cnt1=0;
            for(int i=0;i<nums1.size();i++){
                 if(nums1[i]%2==0){
                      if(nums1[i]-odd < 1){
                        t=-1;
                        break;
                      }
                 }
            }
            for(int i=0;i<nums1.size();i++){
                 if(nums1[i]%2!=0){
                    if(nums1[i]-odd < 1){
                        s=-1;
                        break;
                    }
                 }
            }

           if(t==-1 && s==-1){
            return false;
           }
           return true;
    }
};