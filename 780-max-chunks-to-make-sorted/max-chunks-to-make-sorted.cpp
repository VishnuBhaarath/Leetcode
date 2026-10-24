class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt=0;
        map<int,int> umap;
        int k=0;
        int sz=0;

        for(int i=0;i<arr.size();i++){
            umap[arr[i]]+=1;
            sz+=1;
            if(umap[k]==1){
                int t=0;
                for(int j=k;j<=(k+sz-1);j++){
                    if(umap[j]==0){
                        t=1;
                        break;
                    }
                }
                if(t==0){
                    k+=sz;
                    sz=0;
                    cnt+=1;
                    
                }
            }
        }
        return cnt;
    }
};