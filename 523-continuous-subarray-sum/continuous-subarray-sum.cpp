class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long int sum=0;
       // vector<int> v(k+1,0);
        unordered_map<long long int,long long int> v;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long long int r= ((sum%k)+k)%k;
           
            if(r==0){
                if(i>0){
                return true;}
            }
            if(v[r]!=0){
                long long int sz=i-v[r]+1;
                if(sz>1){
                return true;}
            }
            else{
                v[r]=i+1;
            }
            
        }

        return false;
    }
};