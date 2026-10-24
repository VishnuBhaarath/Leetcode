class Solution {
public:
    int maxChunksToSorted(vector<int>& arr1) {
        int n=arr1.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
          v.push_back({arr1[i], i});
        }
        sort(v.begin(), v.end());
        vector<int> arr(n);
       for (int i = 0; i < n; i++) {
        arr[v[i].second] = i;
       }
       


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
        
       // return 1;

    }
};