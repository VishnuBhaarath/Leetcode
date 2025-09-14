class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       long long int bit=0;
        int one=0;
        int two=0;
        for(int i=0;i<nums.size();i++){
            bit=bit^nums[i];
        }
        cout<<bit;
        cout<<" ";
        bit=(bit&(bit-1))^(bit);
        cout<<bit;
        cout<<" ";
        int j=0;
        
 
for (int i = 0; i <= 31; i++) {
    if (bit & (1 << i)) {
        j = i;
        break;
    }
}
        cout<<j;
        cout<<"\n";
      
        for(int i=0;i<nums.size();i++){
            if (nums[i] & (1 << j)) {
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