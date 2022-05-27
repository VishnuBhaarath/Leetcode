class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int prev=pairs[0][1];
        int cnt=0;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>prev){
                cnt+=1;
                prev=pairs[i][1];
            }
            else{
                prev=min(prev,pairs[i][1]);
            }
        }
        cnt+=1;
        return cnt;
    }
};