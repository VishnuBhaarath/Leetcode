class Solution {
public:
   
   int ans=0;
   void merge(vector<long long int>&nums,int l, int m,int r,int lower,int upper){
       
         int idx1=l;
         int idx2=m+1;
         vector<long long int> temp;
         vector<long long int> left;
         vector<long long int> right;
         for(int i=l;i<=m;i++){
            left.push_back((long long)(nums[i]));
           
         }
    
         for(int i=m+1;i<=r;i++){
            right.push_back((long long)(nums[i]));
            
         }
         
        

        
          for(int i = 0; i < left.size(); i++){
        long long temp = left[i];
        
        // Find first index where right[j] >= lower + temp
        int start = lower_bound(right.begin(), right.end(), lower + temp) - right.begin();
        
        // Find first index where right[j] > upper + temp
        int end = upper_bound(right.begin(), right.end(), upper + temp) - right.begin();
        
        ans += (end - start);
    }
         while(idx1<=m && idx2<=r){
            if(nums[idx1]<=nums[idx2]){
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

    void mergesort(vector<long long int> &nums,int l, int r,int lower,int upper){
        if(l>=r){
            return;
        }
        while(l<=r){
            int m=l+(r-l)/2;
            mergesort(nums,l,m,lower,upper);
            mergesort(nums,m+1,r,lower,upper);
            merge(nums,l,m,r,lower,upper);
            return ;
        }

    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long long int> presum;

        presum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            presum.push_back((long long)(presum[presum.size()-1])+(long long)(nums[i]));
        }

        mergesort(presum,0,n-1,lower,upper);
   
        for(int i=0;i<presum.size();i++){
            if(presum[i]>=lower && presum[i]<=upper){
                ans+=1;
            }
        }
      
       

        return ans;
    }
};