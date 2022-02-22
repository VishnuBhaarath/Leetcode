class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> umap;
        for(int i=0;i<arr.size();i++){
            umap[((arr[i]%k)+k)%k]+=1;
        }
    
        map<int,int> umap1;
        for(auto x:umap){
          if(x.first==0){
              if((x.second%2)!=0){
                  return false;
              }
          }  
          else{  
          if(umap1[k-x.first]==0){  
           
           int val=umap[k-x.first];
           umap1[k-x.first]+=1;
           umap1[x.first]+=1;   
           if(val==x.second){
                umap[k-x.first]=0;
            }
            else{
                return false;
            }
          }
          }
        }
        return true;
    }
};