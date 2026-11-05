class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        long long cnt=0;
        for(int i=0;i<arr1.size();i++){
            int t=0;
            for(int j=0;j<arr2.size();j++){
                 if(abs(arr1[i]-arr2[j])<=d){
                    t=1;
                    break;
                 }
            }
            if(t==0){
                cnt+=1;
            }
        }
        return cnt;
    }
};