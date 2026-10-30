class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();

        int ans=-1;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,arr[i]);
            if(ans==i){
                cnt+=1;
            }
        }
        return cnt;
    }
};