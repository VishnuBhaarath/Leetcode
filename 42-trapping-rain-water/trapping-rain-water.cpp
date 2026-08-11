class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> left(n,0);
        vector<int> right(n,0);

        int lmax=0;
        for(int i=1;i<n;i++){
            left[i]=height[lmax];
            if(height[i]>height[lmax]){
                lmax=i;
            }
        }

        int rmax=n-1;
        for(int i=n-2;i>=0;i--){
            right[i]=height[rmax];
            if(height[i]>height[rmax]){
                rmax=i;
            }
        }
       
        for(int i=0;i<height.size();i++){
             int j=i-1;
             int k=i+1;
             int l=left[i];
             int r=right[i];
             int tp=height[i];
            
             tp=height[i];

            
             int h=min(l,r);
             if(h>height[i])
             ans+=(h-height[i]);
           

        }
        return ans;
    }
};