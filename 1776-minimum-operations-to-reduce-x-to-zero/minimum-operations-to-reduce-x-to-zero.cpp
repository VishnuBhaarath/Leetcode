class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> v;
        vector<int> v1;
        int ans=-1;
        v.push_back(nums[0]);
        if(nums[0]==x){
            ans=1;
        }
        for(int i=1;i<nums.size();i++){
            v.push_back(v[v.size()-1]+nums[i]);
            if(v[i]==x){
                if(ans==-1){
                    ans=i+1;
                }
                else{
                    ans=min(ans,i+1);
                }
            }
        }
        v1.push_back(nums[n-1]);
        if(nums[n-1]==x){
            ans=1;
        }
        int j=2;
        for(int i=n-2;i>=0;i--){
            v1.push_back(v1[v1.size()-1]+nums[i]);
           
             if(v1[v1.size()-1]==x){
                if(ans==-1){
                    ans=j;
                }
                else{
                    ans=min(ans,j);
                }
            }
            j+=1;
        }
        if(nums[0]>x && nums[n-1]>x){
            return -1;
        }
        if(v[n-1]<x){
            return -1;
        }
        
        for(int i=0;i<v.size();i++){
            int val=x-v[i];
            int l=0;
            int r=n-1;
            int idx=-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(v1[m]>val){
                    r=m-1;
                }
                else if(v1[m]<val){
                    l=m+1;
                }
                else if(v1[m]==val){
                    idx=m;
                    r=m-1;
                }

            }
            if(idx!=-1){
                int val=i+idx+2;
                if(ans==-1){
                    ans=val;
                }
                else{
                    ans=min(ans,val);
                }
            }
        }



        return ans;

    }
};