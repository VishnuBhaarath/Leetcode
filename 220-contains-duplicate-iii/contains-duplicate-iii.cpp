class Solution {
public:
    int check(multiset<long long int> &set,int val,int valueDiff){
        vector<long long int> v;
   
       
        auto it = set.lower_bound((long long)val - valueDiff);
    
    // Check if this element is within range
    if (it != set.end() && *it <= (long long)val + valueDiff) {
        return true;
    }
    return false;
        return 0;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long int> set;
        int n=nums.size();
      
        set.insert(nums[0]);
        int i=0;
        int j=1;
        
        while(j<nums.size()){
          
            if((j-i)<=indexDiff){
           
               if(check(set,nums[j],valueDiff)){
                return true;
               }
                   set.insert(nums[j]);
            
            }
            else{
                 set.erase(set.find(nums[i]));
                 i+=1;

                 if(check(set,nums[j],valueDiff)){
                    return true;
                 }
                   set.insert(nums[j]);
                 
            }
            j+=1;
        }
         return false;
    }
};