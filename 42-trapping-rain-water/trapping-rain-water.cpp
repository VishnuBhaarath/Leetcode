class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans=0;
        int n=height.size();
        int lmax=height[0];
        int rmax=height[n-1];
        int i=1;
        int j=n-2;
        while(i<=j){
             if(lmax<=rmax){
                 if(lmax>height[i]){
                    ans+=(lmax-height[i]);
                 }
                 lmax=max(lmax,height[i]);
                 i+=1;
             }
             else{
                if(rmax>height[j]){
                    ans+=(rmax-height[j]);
                }
                rmax=max(rmax,height[j]);
                j-=1;
             }
        }

        return ans;
    }
};