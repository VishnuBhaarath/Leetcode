class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]+=1;
        }
        priority_queue<pair<int,int>> pq;
        for(auto x:umap){
            pq.push({x.second,x.first});
        }
        int i=0;
        vector<int> v;
        while(i<k){
            pair<int,int> p=pq.top();
            pq.pop();
            v.push_back(p.second);
            i+=1;
        }
        return v;
    }
};