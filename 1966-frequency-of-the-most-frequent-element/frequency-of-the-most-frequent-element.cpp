class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<long long int> psum;
       psum.push_back(0);
for(int i=0;i<nums.size();i++){ 
    long long int sum = psum[psum.size()-1];
    sum += nums[i];
    psum.push_back(sum);
}
     
      int res = 1;
        for(int i=0;i<nums.size();i++){
             int l=0;
             int r=i-1;
              int idx=-1;
             
             while(l<=r){
                 int m=l+(r-l)/2;
                 long long int sum=(long long int)(psum[i+1])-(long long int)(psum[m]);
                 long long int val=(long long int)(nums[i])*(long long int)(i-m+1);
                
                 long long int diff=val-sum;
              
                 if(diff<=k){
                    idx=m;
                    r=m-1;
                 }
                 else{
                    l=m+1;
                 }
                 
             }
         
           
             if(idx!=-1){
              

                res=max(res,(i-idx+1));
             }
            
            
        }
        res=max(res,1);
        return res;
    }
};