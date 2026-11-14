class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       int cnt=-1;
       for(int i=0;i<nums.size();i++){
         int sum=0;
         int k=0;
         for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            k+=1;
            if(sum>0){
                if(k>=l && k<=r){
                    if(cnt==-1){
                        cnt=sum;
                    }
                    else{
                        cnt=min(cnt,sum);
                    }
                }
            }
         }
       }
       return cnt;
     
    }
};