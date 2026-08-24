class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int a=h*w;
            ans=max(ans,a);
            if(height[j]>=height[i]){
                i+=1;
            }
            else{
                j-=1;
            }

        }
return ans;

    }
};