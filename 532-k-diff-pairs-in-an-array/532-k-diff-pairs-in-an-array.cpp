class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
      
        map<pair<int,int>,int> umap1;
        int cnt=0;
        if(k==0){
            for(auto x:umap){
                if(x.second>1){
                    cnt+=1;
                }
            }
            return cnt;
        }
      
        for(int i=0;i<nums.size();i++){
         
            if(umap[nums[i]-k]!=0){
                int a=nums[i];
                int b=nums[i]-k;
                pair<int,int> p={a,b};
                if(b<a){
                    p={b,a};
                }
                if(umap1[p]==0){
                    umap1[p]+=1;
                    cout<<p.first;
                    cout<<" ";
                    cout<<p.second;
                    cout<<"\n";
                    cnt+=1;
                }
            }
            else{
                if(umap[nums[i]+k]!=0){
                    int a=nums[i];
                    int b=nums[i]+k;
                    pair<int,int> p={a,b};
                    if(b<a){
                        p={b,a};
                    }
                    if(umap1[p]==0){
                        umap1[p]+=1;
                    cout<<p.first;
                    cout<<" ";
                    cout<<p.second;
                    cout<<"\n";
                        umap1[p]+=1;
                        cnt+=1;
                    }
                }
            }
        }
        return cnt;
    }
};