class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0;
        map<int,int> umap;
        int k=0;
        int sz=0;
        int ans=-1;
        for(int i=0;i<arr.size();i++){
           umap[arr[i]]+=1;
            ans=max(ans,arr[i]);
            sz+=1;
            if(umap[k]>0){
                int t=0;
                if(k+sz-1!=ans){
                    t=1;
                }
               
                if(t==0){
                    k+=sz;
                    sz=0;
                    cnt+=1;
                    ans=-1;
                    
                }
            }
        }
        return cnt;
    }
};