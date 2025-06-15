class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxarea=0;

        while(i<=j){
           int ht=min(height[i],height[j]);
           int wt=j-i;
           int area=ht*wt;
           maxarea=max(area,maxarea);
           if(height[i]<height[j]){
            i+=1;
           }
           else{
            j-=1;
           }
        }

        return maxarea;
    }
};