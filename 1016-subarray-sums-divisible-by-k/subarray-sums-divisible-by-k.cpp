class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> v(k+1,0);
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r=((sum%k)+k)%k;
            if(r==0){
                cnt+=1;
            }
            cnt+=v[r];

            v[r]+=1;
        }
        return cnt;
    }
};