class Solution {
public:
    int minAllOneMultiple(int k) {
        int remainder=0;
   
        for(int i=0;i<=k;i++){
          remainder=((remainder*10)+1)%k;
       
          if(remainder==0){
            return i+1;
          }
       
        
       
        }
        return -1;
        
    }
};