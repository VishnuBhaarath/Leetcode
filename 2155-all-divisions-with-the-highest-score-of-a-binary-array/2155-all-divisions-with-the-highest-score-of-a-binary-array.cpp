class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> v1(n,0);
        vector<int> v2(n,0);
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt+=1;
            }
            v1[i]=cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                cnt+=1;
            }
            v2[i]=cnt;
        }
       
        int ans=0;
        vector<int> v;
        for(int i=0;i<v1.size();i++){
            if(i==0){
                ans=max(ans,v2[i]);
            }
            else{
                ans=max(ans,v1[i-1]+v2[i]);
            }
        }
        ans=max(ans,v1[n-1]);
       
        for(int i=0;i<v1.size();i++){
            if(i==0){
                if(ans==v2[i]){
                    v.push_back(i);
                }
            }
            else{
                if(ans==v1[i-1]+v2[i]){
                    v.push_back(i);
                }
            }
        }
       if(ans==v1[n-1]){
           v.push_back(n);
       }
        return v;
    }
};