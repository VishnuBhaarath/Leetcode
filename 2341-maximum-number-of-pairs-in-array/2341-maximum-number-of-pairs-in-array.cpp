class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        int cnt1=0;
        int cnt2=0;
        for(auto x:umap){
            if(x.second%2==0){
                cnt1+=(x.second/2);
            }
            else{
                cnt1+=(x.second/2);
                cnt2+=1;
            }
        }
        vector<int> v;
        v.push_back(cnt1);
        v.push_back(cnt2);
        return v;
    }
};