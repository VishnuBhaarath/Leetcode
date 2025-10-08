class Solution {
public:
    
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
     
        unordered_map<int,int> umap;
        vector<int> v1(n,0);
        vector<int> v2(n,-1);
        for(int i=0;i<rains.size();i++){
            if(rains[i]!=0){
                if(umap[rains[i]]==0){
                    umap[rains[i]]=i+1;
                }
                else{
                    int l=umap[rains[i]];
                    int r=umap[rains[i]]-1;
                    int t=1;
                 
                    for(int j=l;j<i;j++){
                      
                        if(v1[j]>0){
                            v2[j]=rains[r];
                            v1[j]-=1;
                            t=0;
                            break;
                        }
                        
                    }
                  
                    umap[rains[i]]=i+1;
                    if(t==1){
                        vector<int> ans;
                        return ans;
                    }

                }
            }
            else{
                v2[i]=1;
                v1[i]+=1;
               
            }
        }
        return v2;
    }
};