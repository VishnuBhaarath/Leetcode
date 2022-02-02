class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int r=1;
        int c=2;
        int cnt=0;
        int n=rows*cols;
        vector<vector<int>> ans;
        while(1){
            int i=0;
            int j=0;
          
            while(j<c){
                cout<<rStart;
                cout<<" ";
                cout<<cStart;
                if((rStart<rows && cStart<cols) &&(rStart>=0 && cStart>=0)){
                    ans.push_back({rStart,cStart});
                }
               
                cStart+=1;
                j+=1;
            }
            if(cnt!=0){
                c+=1;
            }
      
            
            cStart-=1;
            j=0;
        
            rStart+=1;
             
            while(i<r){
              
                 if((rStart<rows && cStart<cols) &&(rStart>=0 && cStart>=0)){
                   ans.push_back({rStart,cStart});
                }
                rStart+=1;
                i+=1;
            }
           
            rStart-=1;
            cStart-=1;
            i=0;
            r+=1;
           
            while(j<c){
                
                 if((rStart<rows && cStart<cols) &&(rStart>=0 && cStart>=0)){
                    ans.push_back({rStart,cStart});
                }
                
                cStart-=1;
                j+=1;
            }
            
            cStart+=1;
            rStart-=1;
            c+=1;
            j=0;
             
            while(i<r){
              
                 if((rStart<rows && cStart<cols) &&(rStart>=0 && cStart>=0)){
                    ans.push_back({rStart,cStart});
                }
                i+=1;
                rStart-=1;
            }
            
            rStart+=1;
            cStart+=1;
            r+=1;
          
            i=0;
            j=0;
            cnt+=1;
            if(ans.size()==n){
                return ans;
            }
        }
       
        return ans;
    }
};