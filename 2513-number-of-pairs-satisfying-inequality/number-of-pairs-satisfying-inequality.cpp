class Solution {
public:
long long int ans=0;
void merge(vector<int>& nums,int l, int m, int r,int diff){
    
        int idx1=l;
        int idx2=m+1;
        vector<long long int> left;
        vector<long long int> right;
        for(int i=l;i<=m;i++){
            left.push_back((long long)(nums[i]));
    
        }
        for(int i=m+1;i<=r;i++){
            right.push_back((long long)(nums[i]));
        }
       // sort(right.begin(),right.end());
        for(int i=0;i<left.size();i++){
            long long int num=left[i];
            long long int cnt=0;
            int l1=0;
            int r1=right.size()-1;
            int sz=right.size();
            while(l1<=r1){
                int m1=l1+(r1-l1)/2;
                if((long long int)(num)<=((long long)(right[m1])+(long long)(diff))){
                      cnt = sz-m1;
                      r1=m1-1;
                }
                else{
                     l1=m1+1;
                }
            }
           ans+=cnt;
        }
         vector<int> temp;
         while(idx1<=m && idx2<=r){
            if(nums[idx1]<nums[idx2]){
                temp.push_back(nums[idx1]);
                idx1+=1;
            }
            else{
                temp.push_back(nums[idx2]);
                idx2+=1;
            }
        }
        while(idx1<=m){
            temp.push_back(nums[idx1]);
            idx1+=1;
        }
        while(idx2<=r){
            temp.push_back(nums[idx2]);
            idx2+=1;
        }
        int j=0;
        for(int i=l;i<=r;i++){
            nums[i]=temp[j];
            j+=1;
        }






} 


   void mergesort(vector<int> & nums,int l, int r, int diff){
     if(l>=r){
        return;
     }
     int m=l+(r-l)/2;
     mergesort(nums,l,m,diff);
     mergesort(nums,m+1,r,diff);
     merge(nums,l,m,r,diff);
   }


    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        int l=0;
        int r=n-1;
        vector<int> nums;
        for(int i=0;i<nums1.size();i++){
            nums.push_back(nums1[i]-nums2[i]);
        }
        mergesort(nums,0,r,diff);
        
        return ans;
    }
};