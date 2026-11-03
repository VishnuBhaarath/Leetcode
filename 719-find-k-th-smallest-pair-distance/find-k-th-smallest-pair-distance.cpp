class Solution {
public:
    int check(vector<int>& nums, int m) {
    int cnt = 0, i = 0, n = nums.size();
    for (int j = 0; j < n; j++) {
        while (nums[j] - nums[i] > m) i++;
        cnt += j - i;   // pairs (i,j), (i+1,j), ..., (j-1,j)
    }
    return cnt;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int h=nums[n-1]-nums[0];
        int l=h;
        for(int i=1;i<nums.size();i++){
            l=min(l,nums[i]-nums[i-1]);
        }
int ans=-1;
        while(l<=h){
           int m=l+(h-l)/2;
           cout<<l;
           cout<<" ";
           cout<<h;
           cout<<" ";
           cout<<m;
           cout<<"\n";
           int val= check(nums,m);
           if(val>=k){
            ans=m;
            h=m-1;
           }
           else if(val<k){
            l=m+1;
           }
   
        }
        return ans;
    }
};