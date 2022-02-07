class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<nums.size();i++){
            if((i%2)==0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int j=0;
        int k=odd.size()-1;
        for(int i=0;i<nums.size();i++){
            if((i%2)==0){
                nums[i]=even[j];
                j+=1;
            }
            else{
                nums[i]=odd[k];
                k-=1;
            }
        }
        return nums;
    }
};