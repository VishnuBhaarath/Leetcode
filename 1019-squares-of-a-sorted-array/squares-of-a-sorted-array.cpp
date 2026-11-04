class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        int i=0;
        int j=n-1;
        int k=n-1;
        while(i<=j){
            if(abs(nums[j])>=abs(nums[i])){
                v[k]=(nums[j])*(nums[j]);
                j-=1;
                k-=1;
            }
            else{
                v[k]=(nums[i])*(nums[i]);
                k-=1;
                i+=1;
            }

        }
        return v;
    }
};