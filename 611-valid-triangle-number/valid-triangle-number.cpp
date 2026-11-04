class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        long long cnt=0;
        while(i<n){
            int j=i+1;
            while(j<n){
                int l=j+1;
                int r=n-1;
                int val=nums[i]+nums[j];
               
                int idx=-1;
                while(l<=r){
                    int m=l+(r-l)/2;
                    if(nums[m]>=val){
                       
                        r=m-1;
                    }
                    else{
                        idx=m;
                        l=m+1;
                    }
                }
                if(idx!=-1){
                    cnt+=(idx-j);
                }
                j+=1;
            }
            i+=1;
            
        }


        return cnt;
    }
};