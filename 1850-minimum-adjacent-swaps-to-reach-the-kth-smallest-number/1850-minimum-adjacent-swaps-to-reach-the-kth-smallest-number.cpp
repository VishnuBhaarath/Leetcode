class Solution {
public:
    int getMinSwaps(string nums, int k) {
        int cnt=0;
        string num1=nums;
        while(cnt<k){
        int n=nums.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
          int prev=nums[idx+1];
            int idx1=idx+1;
          for(int i=idx+1;i<n;i++){
              if(nums[i]>nums[idx]){
                  if(nums[i]<=prev){
                      prev=nums[i];
                      idx1=i;
                  }
                
              }
             
          }  
            swap(nums[idx],nums[idx1]);
            
            reverse(nums.begin()+idx+1,nums.end());
        }
        cnt+=1;
            
        }
        cout<<nums;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(num1[i]!=nums[i]){
                int idx=-1;
               for(int j=i+1;j<nums.size();j++){
                   if(num1[j]==nums[i]){
                       idx=j;
                       break;
                    
                   }
               }
               for(int j=idx;j>i;j--){
                   swap(num1[j],num1[j-1]);
                   ans+=1;
               }
            }
        }
        cout<<"\n";
        cout<<ans;
        return ans;
    }
};