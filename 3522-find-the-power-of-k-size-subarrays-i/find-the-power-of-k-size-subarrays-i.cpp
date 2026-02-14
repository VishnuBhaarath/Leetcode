class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
 
        vector<int> ans;
        
        int j=1;
        int i=0;
      
        while(j<nums.size()){
           
             if((nums[j]-nums[j-1]==1)){
               // s.insert(nums[j]);
                if((j-i+1)==k){
                   
                   ans.push_back(nums[j]);
                   i+=1;
                 
                   

                }

             }
             else{
               
                int l=nums.size()-i;
                if(l<k){
                    return ans;
                }
                int t=0;
                while(t<(j-i)){
               
                    ans.push_back(-1);
                    t+=1;
                    l-=1;
                    if(l<k){
                        return ans;
                    }
                }
                
              
              
                i=j;
                 
             }
             j+=1;
            
        }
      //  vector<int> ans;

        return ans;
    }
};