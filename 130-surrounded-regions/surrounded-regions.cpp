class Solution {
public:
    void func(int i,int j,vector<vector<char>>& board,int n,int m,vector<vector<int>> &visited){
        vector<int> r={1,-1,0,0};
        vector<int> c={0,0,1,-1};
        queue<pair<int,int>> q;
       
        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz>0){
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++){
                int x1=x+r[i];
                int y1=y+c[i];
                if((x1>=0 && x1<n) && (y1>=0 && y1<m)){
                     if(board[x1][y1]=='O'){
                         if(visited[x1][y1]==0){
                             q.push({x1,y1});
                             visited[x1][y1]=1;
                         }
                     }
                }
            }
            sz-=1;
            }

        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
{
            func(i,0,board,n,m,visited);}
            if(board[i][m-1]=='O'){
            func(i,m-1,board,n,m,visited);}
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O')
            func(0,j,board,n,m,visited);
            if(board[n-1][j]=='O'){
            func(n-1,j,board,n,m,visited);}
        
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='O'){
                    if(visited[i][j]==0){
                        board[i][j]='X';
                    }
                }
            }
        }
    }
};