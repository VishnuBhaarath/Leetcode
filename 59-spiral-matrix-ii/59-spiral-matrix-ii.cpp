class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> v(n,0);
        vector<vector<int>> ans(n,v);
        int r=0;
        int c=0;
        
        int c1=0;
        int c2=n;
        int r1=0;
        int r2=n;
        int num=1;
        while(1){
         
          while(c<c2){
            
            
            ans[r][c]=num;
            num+=1;  
          
             c+=1;
          }
           c-=1;
           r+=1; 
           if(r>=r2){
               break;
           }
           while(r<r2){
              ans[r][c]=num;
              num+=1; 
              
               r+=1;
               
           } 
           r-=1;
           c-=1;
           if(c<c1){
               break;
           }
           while(c>=c1){
              ans[r][c]=num;
              num+=1; 
            
               c-=1;
           } 
           c+=1;
           r-=1;
           if(r<=r1){
               break;
           } 
           while(r>r1){
              
               ans[r][c]=num;
               num+=1;
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