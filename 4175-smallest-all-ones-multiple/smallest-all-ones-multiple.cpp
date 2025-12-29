class Solution {
public:
    int minAllOneMultiple(int k) {
        int remainder=0;
        map<int,int> umap;
        for(int i=0;i<=k;i++){
          remainder=((remainder*10)+1)%k;
       
          if(remainder==0){
            return i+1;
          }
       
          if(umap[remainder]!=0){
            return -1;
          }
             umap[remainder]+=1;
       
        }
        return 3;
        
    }
};