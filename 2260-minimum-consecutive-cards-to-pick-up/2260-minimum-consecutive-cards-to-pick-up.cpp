class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> umap;
        int ans=-1;
        for(int i=0;i<cards.size();i++){
            if(umap[cards[i]]==0){
                umap[cards[i]]=i+1;
            }
            else{
                int val=i+1-umap[cards[i]]+1;
                if(ans==-1){
                    ans=val;
                }
                else{
                    ans=min(ans,val);
                }
                umap[cards[i]]=i+1;
            }
        }
        return ans;
    }
};