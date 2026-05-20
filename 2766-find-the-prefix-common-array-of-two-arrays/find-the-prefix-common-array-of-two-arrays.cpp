class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> v1(51,0);
        //vector<int> v2(51,0);
        vector<int> ans;
int cnt=0;
        for(int i=0;i<A.size();i++){
            if(v1[A[i]]==0){
                v1[A[i]]=1;
            }
            else{
                cnt+=1;
            }
            if(v1[B[i]]==0){
                v1[B[i]]=1;
            }
            else{
                cnt+=1;
            }
ans.push_back(cnt);
        }
        return ans;
    }
};