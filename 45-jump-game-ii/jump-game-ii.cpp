class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        int l=nums[0];
        int r=0;
        if(n==1){
            return 0;
        }
        int cnt=1;

        for(int i=1;i<nums.size();i++){
             if(i<=l){
                 r=max(r,i+nums[i]);
                 if(i==l){
                     if(i==n-1){
                        return cnt;
                     }
                     l=r;
                     cnt+=1;
                     r=0;
                 }
             }
        }

        return cnt;
    }
};