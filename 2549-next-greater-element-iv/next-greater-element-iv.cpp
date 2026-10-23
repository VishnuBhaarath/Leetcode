class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> s;
       
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        int n=nums.size();
        vector<int> v(n,-1);
        for(int i=0;i<nums.size();i++){
            if(!pq.empty()){
                
                while(nums[pq.top().second]<nums[i]){
                    v[pq.top().second]=nums[i];
                    pq.pop();
                    if(pq.empty()){
                        break;
                    }
                }
            }
            if(s.empty()){
                s.push(i);
            }
            else{
                if(nums[i]<=nums[s.top()]){
                    s.push(i);
                }
                else{
                    while(nums[i]>nums[s.top()]){
                        pq.push({nums[s.top()],s.top()});
                        
                        s.pop();
                        if(s.empty()){
                            break;
                        }
                    }
                    s.push(i);
                }
            }
        }
      
        return v;
    }
};