class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        vector<long long > v(n,0);
        map<int,int> umap;
        map<int,int> umap1;
        for(int i=0;i<arr.size();i++){
            if(umap[arr[i]]==0){
                umap[arr[i]]=i+1;
                umap1[arr[i]]+=1;
            }
            else{
                int idx=umap[arr[i]];
                int cnt=umap1[arr[i]];
                int val=i+1-idx;
                int sum=val*cnt;
                v[i]=v[idx-1]+sum;
                umap1[arr[i]]+=1;
                umap[arr[i]]=i+1;
            }
        }
       
        umap.clear();
        umap1.clear();
        
        vector<long long> v1(n,0);
        for(int i=arr.size()-1;i>=0;i--){
            if(umap[arr[i]]==0){
                umap[arr[i]]=i;
                umap1[arr[i]]+=1;
            }
            else{
                int idx=umap[arr[i]];
                int cnt=umap1[arr[i]];
                int val=idx-i;
                int sum=val*cnt;
              
                v1[i]=v1[idx]+sum;
                v[i]+=v1[i];
                umap1[arr[i]]+=1;
                umap[arr[i]]=i;
            }
        }
       
        return v;
    }
};