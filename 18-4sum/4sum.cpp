class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;
        int n=nums.size();
        while(i<n){
            int j=i+1;
            while(j<n){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=(long long)(nums[i])+(long long)(nums[j])+(long long)(nums[k])+(long long)(nums[l]);
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int idx1=l;
                        int idx2=k;
                        while(nums[l]==nums[idx1]){
                            idx1-=1;
                            if(idx1<0){
                                break;
                            }
                        }
                        l=idx1;

                        while(nums[k]==nums[idx2]){
                            idx2+=1;
                            if(idx2>=n){
                                break;
                            }
                        }
                        k=idx2;
                    }
                    else if(sum>target){
                        int idx=l;
                        while(nums[l]==nums[idx]){
                            idx-=1;
                            if(idx<0){
                                break;
                            }
                        }
                        l=idx;
                    }
                    else{
                        int idx=k;
                        while(nums[k]==nums[idx]){
                            idx+=1;
                            if(idx>=n){
                                break;
                            }
                        }
                        k=idx;
                    }

                }
                int idx=j;
                while(nums[idx]==nums[j]){
                    idx+=1;
                    if(idx>=n){
                        break;
                    }
                }
                j=idx;
            }
            int idx=i;
            while(nums[idx]==nums[i]){
                idx+=1;
                if(idx>=n){
                    break;
                }
            }
            i=idx;
        }
        return ans;
    }
};