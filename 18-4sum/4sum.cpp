class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> dp;
        set<vector<int>> dp1;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int k=j+1;
                int l=n-1;
                
                while(k<l){
                   
                    long long int sum=(long long)(nums[i])+(long long)(nums[j])+(long long)(nums[k])+(long long)(nums[l]);
                    
                   
                    if(sum==target){
                        vector<int> v;
                       
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[l]);
                        if(dp1.find(v)!=dp1.end()){

                        }
                        else{
                        dp.push_back(v);
                        dp1.insert(v);}
                        l-=1;
                        k+=1;
                    }
                    else if(sum>target){
                        l-=1;
                    }
                    else if(sum<target){
                        k+=1;
                    }
                }
            }
        }
        return dp;
    }
};