class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> r={1,-1,0,0};
        vector<int> c={0,0,1,-1};
        int ans=1;
        // ADD 1: memo table
        vector<vector<int>> memo(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 stack<pair<pair<int,int>,int>> st;
                 st.push({{i,j},1});
                 while(!st.empty()){
                
                     pair<int,int> p=st.top().first;
                     int d=st.top().second;
                     ans=max(ans,d);
                     st.pop();
                     int x=p.first;
                     int y=p.second;

                     // ADD 2: update memo if we found a longer path
                     memo[x][y] = max(memo[x][y], d);

                     for(int k=0;k<4;k++){
                        int x1=x+r[k];
                        int y1=y+c[k];
                        if(x1>=0 && x1<n){
                             if(y1>=0 && y1<m){
                                 if(matrix[x1][y1]>matrix[x][y]){
                                    // ADD 3: skip if we already know a longer/equal path from here
                                    if(memo[x1][y1] == 0 || memo[x1][y1] < d+1){
                                        st.push({{x1,y1},d+1});
                                    }
                                 }
                             }
                        }
                     }
                 
                     }
                 }
        
        }
return ans;
    }
};