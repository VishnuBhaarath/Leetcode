class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        map<int,int> umap;
        int cnt=0;
        int ans=1;
        while(j<n){
            if(umap[fruits[j]]!=0){
                umap[fruits[j]]+=1;
                int sz=(j-i+1);
                ans=max(ans,sz);
                j+=1;
            }
            else{
                if(cnt<2){
                    cnt+=1;
                    umap[fruits[j]]+=1;
                    int sz=(j-i+1);
                    ans=max(ans,sz);
                    j+=1;
                }
                else{
                    while(1){
                        umap[fruits[i]]-=1;
                        if(umap[fruits[i]]==0){
                            i+=1;
                            break;
                        }
                        i+=1;
                    }
                    umap[fruits[j]]+=1;
                     int sz=(j-i+1);
                    ans=max(ans,sz);
                    j+=1;
                }
            }
        }
        return ans;
    }
};