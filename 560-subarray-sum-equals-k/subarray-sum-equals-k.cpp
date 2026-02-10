class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
         int n=nums.size();
        vector<int> psum;
        psum.push_back(nums[0]);
        unordered_map<int,int> umap;
        for(int i=1;i<nums.size();i++){
             int sum=psum[psum.size()-1]+nums[i];
             psum.push_back(sum);
        }
        
        int cnt=0;
        umap[0]=1;

        for(int i=0;i<psum.size();i++){
             int val=psum[i];
            
             cout<<umap[val-goal];
           
              cnt+=umap[val-goal];
             umap[val]+=1;

        }
       
 
        return cnt;
    }
};