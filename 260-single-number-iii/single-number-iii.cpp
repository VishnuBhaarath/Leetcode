class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       long long int bit=0;
        int one=0;
        int two=0;
        for(int i=0;i<nums.size();i++){
            bit=bit^nums[i];
        }
      
        bit=(bit&(bit-1))^(bit);
      
        int j=0;
        
 

      
        for(int i=0;i<nums.size();i++){
            if (nums[i] & (bit)) {
               one=one^nums[i];
         } else {
               two=two^nums[i];
          }
        }
    
        vector<int> v;
        v.push_back(one);
        v.push_back(two);

        return v;
    }
};