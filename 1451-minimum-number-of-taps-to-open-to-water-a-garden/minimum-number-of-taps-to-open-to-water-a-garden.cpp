class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
         vector<int> line (1+n, 0);
        for(int i =0; i <=n; ++i){
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            line[left] = max(line[left], right);
        }
        // Sweep line
        // Lets 0th tap as best one
        int curr = line[0];
        int next_best = 0;
        int ans = 1;
        for(int i = 1; (i <=n) and (curr < n); ++i){
            // we cannot reach to this ith that means not possible at all !
            if( i > curr)
                return -1;
            else if ( i == curr){
                // curr reach its end , time to select next best
                next_best = max(next_best, line[i]);
                ++ans;
                curr = next_best; // assign next_best to curr 
                next_best =0;//rest next_best as 0
            }
            else{
                // we still are in range of curr, no need to open a new tap but keep checking what next best tap of highest range we can open next.
                next_best = max(next_best, line[i]);
            }
        }
        return ans;;
    }
};