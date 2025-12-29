class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int idx=-1;
        for(int i=1;i<nums.size();i++){
            pq.push({nums[i],i});
        }
       
        long long int val=INT_MAX;
        long long int val1=INT_MIN;
        long long int sum=0;
        for(int i=0;i<nums.size()-1;i++){
            
            sum+=nums[i];
            while(pq.top().second<=i){
                pq.pop();
            }
           
         
            long long int ans=sum-pq.top().first;
            if(i==0){
                val1=ans;
            }
            else{
                if(ans>val1){
                    val1=ans;
                }
            }
           

        }
        return val1;
    }
};