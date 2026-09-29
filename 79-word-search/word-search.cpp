class Solution {
public:
   int t=0;
   void func(int i,int j, vector<vector<char>>& board, string & word,int n,int m,string st,vector<vector<int>> &dp){
          
            if(i==n || j==m){
                return;
            }
            if(i<0 || j<0){
                return;
            }
            if(t==1){
                return;
            }
             
            
            if(word==st){
           
                t=1;
              
                return;
            }
            
            
            if(i+1<n){
                if(dp[i+1][j]==0){
                    int sz=st.size();
                    if(word[sz]==board[i+1][j]){
                        st+=board[i+1][j];
                        dp[i+1][j]=1;
                        func(i+1,j,board,word,n,m,st,dp);
                        st.pop_back();
                        dp[i+1][j]=0;
                    }
                }
            }
            if(j+1<m){
                 if(dp[i][j+1]==0){
                    int sz=st.size();
                   
                    if(word[sz]==board[i][j+1]){
                        st+=board[i][j+1];
                        dp[i][j+1]=1;
                        func(i,j+1,board,word,n,m,st,dp);
                         st.pop_back();
                      
                        dp[i][j+1]=0;
                    }
                 }
            }
            if(i-1>=0){
                 if(dp[i-1][j]==0){
                    int sz=st.size();
                    if(word[sz]==board[i-1][j]){
                        st+=board[i-1][j];
                        dp[i-1][j]=1;
                        func(i-1,j,board,word,n,m,st,dp);
                         st.pop_back();
                        dp[i-1][j]=0;
                    }
                }

            }
            if(j-1>=0){
                 if(dp[i][j-1]==0){
                    int sz=st.size();
                    if(word[sz]==board[i][j-1]){
                        st+=board[i][j-1];
                        dp[i][j-1]=1;
                        func(i,j-1,board,word,n,m,st,dp);
                         st.pop_back();
                        dp[i][j-1]=0;
                    }
                }
            }
           return;
        
 
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
       
       // dp[i][j]=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                string st="";
                st+=board[i][j];
                dp[i][j]=1;
                func(i,j,board,word,n,m,st,dp);
                dp[i][j]=0;
                if(t==1){
                    return true;
                }
            }
        }
       if(t==0){
        return false;
       }
        return true;
    }
};