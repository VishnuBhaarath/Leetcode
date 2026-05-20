class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> v1(51,0);
        vector<int> v2(51,0);
        vector<int> ans;

        for(int i=0;i<A.size();i++){
            v1[A[i]]+=1;
            v2[B[i]]+=1;
            int cnt=0;
            for(int i=0;i<v1.size();i++){
                 if(v1[i]==v2[i]){
                    if(v1[i]!=0){
                    cnt+=1;}
                 }
            }
ans.push_back(cnt);
        }
        return ans;
    }
};