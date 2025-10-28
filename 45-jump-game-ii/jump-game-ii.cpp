class Solution {
public:
    int jump(vector<int>& nums) {
        int val=nums[0];
        int steps=1;
        int val1=0;
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if(val>=(n-1)){
            return steps;
        }
        for(int i=1;i<nums.size();i++){
          
            if(val>=i){
                val1=max(val1,(i+nums[i]));
             
                if(val1>=(n-1)){
                    return steps+1;
                }
                if(val==i){
                    val=val1;
                    steps+=1;
                    val1=0;
                }
            }
           
        }
        return steps;
    }
};