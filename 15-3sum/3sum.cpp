class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> dp;
        set<vector<int>> dp1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                long long int sum=nums[i]+nums[j];
                if(sum>0){
                    if(nums[k]>0){
                        break;
                    }
                }
                if((sum+nums[k])==0){
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    if (dp1.find(v) != dp1.end()) {

                    } 
                    else{
 dp1.insert(v);
                        dp.push_back(v);
                    }
                    
                    
                    int temp=nums[k];
                    k=k-1;
                    while(nums[k]==temp){
                        k-=1;
                        if(k<=j){
                            break;
                        }
                    }
                    int temp1=nums[j];
                    j=j+1;
                    while(nums[j]==temp1){
                        j+=1;
                        if(k<=j){
                            break;
                        }
                    }
                }
                else if((abs(sum))>nums[k]){
                    j+=1;
                }
                else if((abs(sum))<nums[k]){
                    k-=1;
                }

            }
        }
        return dp;
    }
};