class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,vector<int>> umap;
        for(int i=0;i<nums.size();i++){
             umap[nums[i]].push_back(i);
        }
       
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
             int val=nums[queries[i]];
          
             vector<int> &v=umap[val];
            
             if(v.size()<=1){
                ans.push_back(-1);
             }
             else{
                int l=0;
                int r=v.size()-1;
                int idx=-1;
                while(l<=r){
                    int m=l+(r-l)/2;
                    if(v[m]<=queries[i]){
                        l=m+1;
                    }
                    else{
                        r=m-1;
                        idx=m;
                    }
                  

                }
                        
              if (idx == -1) {
    // All occurrences are to the left; closest left = v[v.size()-2]
    // Closest right (wrap) = v[0]
    int rightDist = (int)nums.size() - queries[i] + v[0];
    int leftDist  = queries[i] - v[v.size() - 2]; // second last, since last == queries[i]
    ans.push_back(min(rightDist, leftDist));
} else {
   int bestDist = INT_MAX;

    // Right neighbor
    bestDist = min(bestDist, v[idx] - queries[i]);

    // Left neighbor (idx-1, but skip if it's the query index itself)
    if (idx - 2 >= 0 && v[idx-2] != queries[i]) {
        bestDist = min(bestDist, queries[i] - v[idx-2]);
    }
     if(v[0]==queries[i]){
        int dist=v[0]+nums.size()-v[v.size()-1];
        bestDist=min(dist,bestDist);
        
     }
    // Circular: wrap to v[0] from right end
    //int wrapRight = (int)nums.size() - queries[i] + v[0];
   // bestDist = min(bestDist, wrapRight);

    ans.push_back(bestDist);
}
        
                
             }
         
           
        }

        return ans;
    }
};