class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int i=0;
        int j=1;
        int cnt=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                nums[i+1]=nums[j];
                j+=1;
                cnt+=1;
               
            }
            else{
                if(cnt>=2){
                  nums[i+2]=nums[j];
                  i=i+2;
                  j+=1;
                  cnt=1;
                }
                else{
                    nums[i+1]=nums[j];
                        i+=1;
                        j+=1;
                    
                  cnt=1;
                }
               
            }
        }
   
        if(cnt>=2){
            nums[i+1]=nums[i];
            i+=1;
        }
        
       
        return i+1;
    }
};