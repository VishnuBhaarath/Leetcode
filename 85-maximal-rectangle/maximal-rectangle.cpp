class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        int n=heights.size();
        int marea=0;
        stack<int> s;
        for(int i=0;i<heights.size();i++){
           if(s.empty()){
             s.push(i);
           }
           else{
              if(heights[i]>=heights[s.top()]){
                s.push(i);
              }
              else{
                while(heights[s.top()]> heights[i]){
                     int tp=s.top();
                     int h=heights[s.top()];
                    
                     int w=i-s.top();
                      s.pop();
                      int tp1=-1;
                      if(!s.empty()){
                        tp1=s.top();
                      }
                      w+=(tp-tp1-1);

                     int area=h*w;
                     marea=max(marea,area);
                     
                     if(s.empty()){
                        break;
                     }
                }
                s.push(i);
                
              }
           }
        }
       
        vector<int> v;
        while(!s.empty()){
           v.push_back(s.top());
           s.pop();
        }
        int m=v.size();
        reverse(v.begin(),v.end());
        int r=v[m-1];
        int l=0;
        for(int i=m-1;i>=0;i--){
              int w=r-v[i];
              w+=1;
              if(i==0){
                w+=(v[i]-l);
              }
              else{
                int d=v[i]-v[i-1];
                d-=1;
                w+=d;
              }
              int h=heights[v[i]];
              int area=h*w;
             
              marea=max(marea,area);

        }
        return marea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    dp[i+1][j]=1+dp[i][j];
                }
            }
        }
      
       int ans=0;
       for(int i=0;i<dp.size();i++){
         ans=max(ans,largestRectangleArea(dp[i]));
       }
        return ans;
    }
};