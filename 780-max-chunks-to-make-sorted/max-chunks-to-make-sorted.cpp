class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0;
        unordered_map<int,int> umap;
        int k=0;
        int sz=0;
        int ans=-1;
         int t=0;
        for(int i=0;i<arr.size();i++){
          // umap[arr[i]]+=1;
            ans=max(ans,arr[i]);
            sz+=1;
            if(arr[i]==k || t==1){
               
                if(k+sz-1==ans){
                   
               
               
                    k+=sz;
                    sz=0;
                    cnt+=1;
                    ans=-1;
                    t=0;
                    
                
                }
                else{
                    t=1;
                }
            }
        }
        return cnt;
    }
};