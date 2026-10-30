class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int n=arr.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
          v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        vector<int> arr1(n);
       for (int i = 0; i < n; i++) {
        arr1[v[i].second] = i;
       }
       
        int ans=-1;
        int cnt=0;
        for(int i=0;i<arr1.size();i++){
            ans=max(ans,arr1[i]);
            if(ans==i){
                cnt+=1;
            }
        }
        return cnt;

        return 1;
    }
};