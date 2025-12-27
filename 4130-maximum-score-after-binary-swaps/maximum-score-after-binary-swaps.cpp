class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int> pq;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                pq.push(nums[i]);
            }
            else{
                pq.push(nums[i]);
                ans+=pq.top();
                pq.pop();
            }
        }
        
        return ans;
    }
};