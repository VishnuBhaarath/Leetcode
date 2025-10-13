class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp =mat;
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                q.push({i,j});}
            }
        }
        int val=1;
        while(!q.empty()){
           int sz=q.size();
            int t=false;
          
           while(sz){

              int x=q.front().first;
              int y=q.front().second;
            
              q.pop();

              if(x-1>=0 && mat[x-1][y]==1){
                  q.push({x-1,y});
                  mat[x-1][y]=0;
                  dp[x-1][y]=val;
                  t=true;
              }
              if(x+1<n && mat[x+1][y]==1){
                  q.push({x+1,y});
                   mat[x+1][y]=0;
                  dp[x+1][y]=val;
                  t=true;
              }
              if(y-1>=0 && mat[x][y-1]==1){
                    q.push({x,y-1});
                    mat[x][y-1]=0;
                  dp[x][y-1]=val;
                    t=true;
              }
              if(y+1<m && mat[x][y+1]==1){
                  q.push({x,y+1});
                   mat[x][y+1]=0;
                  dp[x][y+1]=val;
                  t=true;
              }

              sz-=1;
           }
           if(t){
              val+=1;
           }
        }


        return dp;
    }
};