class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        cout<<n;
        cout<<" ";
        cout<<m;
        cout<<"\n";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                cout<<board[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=1;i<(n-1);i++){
            for(int j=1;j<(m-1);j++){
                if(board[i][j]=='O'){
                    if(dp[i][j]==0){
                         queue<pair<int,int>> q;
                         dp[i][j]=1;
                         vector<pair<int,int>> v;
                         q.push({i,j});
                         v.push_back({i,j});
                         int t=0;
                        
                         while(!q.empty()){
                            int x=q.front().first;
                            int y=q.front().second;
                            
                            q.pop();
                            if(x-1 >=0){
                            if(board[x-1][y]=='O'){
                                if(dp[x-1][y]==0){
                                    if(x-1 ==0){
                                        t=1;
                                    }
                                    else{
                                       v.push_back({x-1,y});
                                    }
                                    dp[x-1][y]=1;
                                     q.push({x-1,y});
                                }
                            }
                            }

                            if(x+1 < n){
                            if(board[x+1][y]=='O'){
                                if(dp[x+1][y]==0){
                                    if(x+1 == n-1){
                                        t=1;
                                    }
                                    else{
                                       v.push_back({x+1,y});
                                    }
                                    dp[x+1][y]=1;
                                     q.push({x+1,y});
                                }
                            }
                            }

                               if(y-1 >= 0){
                            if(board[x][y-1]=='O'){
                                if(dp[x][y-1]==0){
                                    if(y-1 == 0){
                                        t=1;
                                    }
                                    else{
                                       v.push_back({x,y-1});
                                    }
                                    dp[x][y-1]=1;
                                     q.push({x,y-1});
                                }
                            }
                            }

                            if(y+1 < m){
                            if(board[x][y+1]=='O'){
                                if(dp[x][y+1]==0){
                                    if(y+1 == m-1){
                                        t=1;
                                    }
                                    else{
                                       v.push_back({x,y+1});
                                    }
                                    dp[x][y+1]=1;
                                     q.push({x,y+1});
                                }
                            }
                            }
                            
                          
                            
                         }
                       
                         if(t==0){
                            for(int i=0;i<v.size();i++){
                                board[v[i].first][v[i].second]='X';
                            }
                         }
                    }
                }
            }
        }
    }
};