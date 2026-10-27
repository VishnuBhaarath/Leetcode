class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        long long ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int l=heights[i];
            long long val=0;
            for(int j=i-1;j>=0;j--){
                if(heights[j]>l){
                    val+=l;
                }
                else{
                    val+=heights[j];
                     l=heights[j];
                }
               
            }
            int r=heights[i];
            for(int j=i+1;j<n;j++){
                if(heights[j]>r){
                    val+=r;
                }
                else{
                    val+=heights[j];
                     r=heights[j];
                }
               
            }
              val+=heights[i];
           
          
            ans=max(ans,val);

        }

        return ans;
    }
};