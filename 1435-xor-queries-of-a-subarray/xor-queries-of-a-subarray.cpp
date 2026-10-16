class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> psum;
        psum.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            int temp=psum[psum.size()-1];
            temp^=arr[i];
            psum.push_back(temp);
        }
        vector<int> v;
       
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0){
                v.push_back(psum[r]);
            }
            else{
                v.push_back(psum[r]^psum[l-1]);
            }
        }
        return v;
    }
};