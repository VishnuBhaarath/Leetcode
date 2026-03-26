class Solution {
public:
    vector<int> r={1,-1,0,0};
    vector<int> c={0,0,1,-1};
    int t=0;
    void func(int i,int j,int n,int m,vector<vector<char>>& board,string s,string word,vector<vector<int>>&visited){
   
      if(t==1)
       return;
      if(word==s){
         t=1;
         return;
      }
      if(s.size()>=word.size()){
        return;
      }

       for(int k=0;k<4;k++){
        int x=i+r[k];
        int y=j+c[k];
         if((x>=0 && x<n) && (y>=0 && y<m)){
            if(visited[x][y]==0){
             int sz=s.size();
            
             if(word[sz]==board[x][y]){
             s+=board[x][y];
             visited[x][y]=1;
             func(x,y,n,m,board,s,word,visited);
             s.pop_back();
             visited[x][y]=0;}}
         }
       }

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        if(n*m<word.size()){
            return false;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(board[i][j]==word[0]){
                     string s="";
                     t=0;
                     s+=board[i][j];
                     vector<vector<int>> visited(n,vector<int>(m,0));
                     visited[i][j]=1;
                     func(i,j,n,m,board,s,word,visited);
                     if(t==1){
                        return true;
                     }
                 }
            }
        }
        
        if(t==0){
            return false;
        }
        return true;
    }
};