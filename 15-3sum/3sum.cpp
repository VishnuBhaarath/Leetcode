class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            int j=i+1;
            int k=n-1;
            map<pair<int,int>,int> umap;
            while(j<k){
                 if(nums[i]+nums[j]+nums[k]==0){
                    
                         ans.push_back({nums[i],nums[j],nums[k]});
                       
                     int idx1=j;
                     int idx2=k;
                     while(nums[idx1]==nums[j]){
                        idx1+=1;
                        if(idx1==n || idx1>=k){
                            break;
                        }
                     }
                     while(nums[idx2]==nums[j]){
                        idx2-=1;
                        if(idx2<0 || idx2<=j){
                            break;
                        }

                     }
                     j=idx1;;
                     k=idx2;
                 }
                 else if(nums[i]+nums[j]+nums[k]>0){
                    int idx=k;
                    while(nums[k]==nums[idx]){
                        idx-=1;
                        if(idx<0 || idx<=j){
                            break;
                        }
                        
                    }
                    k=idx;
                 }
                 else{
                    int idx=j;
                    while(nums[j]==nums[idx]){
                        idx+=1;
                        if(idx==n || idx>=k){
                            break;
                        }
                    }
                    j=idx;
                 }
            }
           j=i+1;
           if(i+1 >=n){
            break;
           }
            while(nums[j]==nums[i]){
                j+=1;
                if(j>=n){
                    i=j;
                    break;
                }
            }
            i=j;
        }
        return ans;
    }
};