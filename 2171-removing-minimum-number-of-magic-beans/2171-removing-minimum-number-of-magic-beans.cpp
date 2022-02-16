class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long int n=beans.size();
        long long int ans=-1;
        vector<long long int> presum;
        presum.push_back(beans[0]);
        for(long long int i=1;i<beans.size();i++){
            presum.push_back(presum[presum.size()-1]+beans[i]);
        }
        
        for(long long int i=0;i<beans.size();i++){
            long long int val=presum[n-1]-beans[i]-(n-1-i)*beans[i];
            if(ans==-1){
                ans=val;
            }
            else if(val<ans){
                ans=val;
            }
        }
       
        
       
        return ans;
    }
};