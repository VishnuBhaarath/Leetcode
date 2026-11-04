class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-1;
        long long cnt=0;
        while(i>=0){
             int j=0;
             int k=i-1;
            
             while(j<k){
                 
                  if(nums[k]+nums[j]>nums[i]){
                    cnt+=(k-j);
                    k-=1;
                  }
                  else{
                    j+=1;
                  }
             }
             i-=1;
        }
        
        return cnt;
    }
};