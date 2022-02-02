class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int r=0;
        int c=0;
        int row=n;
        int col=m;
        int c1=0;
        int c2=m;
        int r1=0;
        int r2=n;
        while(1){
          int r0=r;
          int c0=c;
          while(c<c2){
            
            
              ans.push_back(matrix[r][c]);
          
             c+=1;
          }
           c-=1;
           r+=1; 
           if(r>=r2){
               break;
           }
           while(r<r2){
               ans.push_back(matrix[r][c]);
              
               r+=1;
               
           } 
           r-=1;
           c-=1;
           if(c<c1){
               break;
           }
           while(c>=c1){
               ans.push_back(matrix[r][c]);
            
               c-=1;
           } 
           c+=1;
           r-=1;
           if(r<=r1){
               break;
           } 
           while(r>r1){
               ans.push_back(matrix[r][c]);
              
               r-=1;
           } 
           r+=1;
           c+=1;
           c2-=1;
           r2-=1;
           r1+=1;
           c1+=1;
           if(r1>=r2){
               break;
           } 
           if(c1>=c2){
               break;
           } 
     
            
            
        }
        return ans;
    }
};