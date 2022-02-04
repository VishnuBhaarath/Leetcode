class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[n-1];
        vector<int> v;
        v.push_back(prev);
        int idx=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<prev){
                idx=i;
                break;
            }
            else{
                prev=nums[i];
                v.push_back(nums[i]);
            }
        }
        if(idx==-1){
            sort(nums.begin(),nums.end());
        }
        else{
      
        int val=prev;
        
    
        for(int i=0;i<v.size();i++){
            if(v[i]>nums[idx]){
                val=min(val,v[i]);
            }
           
        }
        v.push_back(nums[idx]);
        sort(v.begin(),v.end());
        nums[idx]=val;
        int j=idx+1;
        int t=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=val){
                nums[j]=v[i];
                j+=1;
            }
            else{
                if(t==0){
                    t=1;
                }
                else{
                    nums[j]=v[i];
                    j+=1;
                }
            }
        }
       }
    }
};