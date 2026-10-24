class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> v(n,0);
        vector<int> v1(n,0);

        v[0]=arr[0];
        int val=arr[0];
        for(int i=1;i<arr.size();i++){
            val=max(val,arr[i]);
            v[i]=val;
        }
       v1[n-1] = INT_MAX;
        val=arr[n-1];
        for(int i=n-2;i>=0;i--){
            v1[i]=val;
            val=min(val,arr[i]);
        }
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=v1[i]){
                cnt+=1;
            }
        }
        return cnt;
    }
};