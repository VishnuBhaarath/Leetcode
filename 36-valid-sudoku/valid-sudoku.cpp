class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            map<int,int> umap;
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!='.'){
                 if(umap[board[i][j]]==0){
                    umap[board[i][j]]+=1;
                 }
                 else{
                    return false;
                 }
                 }
            }
        }

         for(int i=0;i<board.size();i++){
            map<int,int> umap;
            for(int j=0;j<board[i].size();j++){
                if(board[j][i]!='.'){
                 if(umap[board[j][i]]==0){
                    umap[board[j][i]]+=1;
                 }
                 else{
                    return false;
                 }
                 }
            }
        }
        
        for(int k=0;k<9;k+=3){
          for(int l=0;l<9;l+=3){
              map<int,int> umap;
              for(int i=k;i<k+3;i++){
                for(int j=l;j<l+3;j++){
                    if(board[i][j]!='.'){
                        if(umap[board[i][j]]==0){
                            umap[board[i][j]]+=1;
                        }
                        else{
                            return false;
                        }
                    }
                }
              }
             
          }
            
        }
        return true;
    }
};