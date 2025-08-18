class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
     
        long long int cnt=0;
        
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(abs(nums[i]));
        }
        sort(v.begin(),v.end());
        int n=v.size();
        int i=0;
        int j=i+1;
        cnt=0;
        while(j<v.size()){
            if(v[j]<=(2*v[i])){
                cnt+=(j-i);
                j+=1;
            }
            else{
                i+=1;
            }
        }
        return cnt;
    }
};