class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        
        for(int i=0;i<nums.size();i++){
            int t=0;
         
            for(int j=1;j<=nums[i];j++){
                int val=j|(j+1);
                
                if(val==nums[i]){
                    v[i]=j;
                    t=1;
                    break;
                }
            }
            if(t==0){
                v[i]=-1;
            }
           
        }
return v;
    }
};