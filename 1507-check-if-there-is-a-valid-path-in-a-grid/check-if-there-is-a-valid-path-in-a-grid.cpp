class Solution {
public:
 queue<pair<pair<int,int>,int> >q;
    void check(int x,int y,vector<vector<int>>& grid){
      
 if(grid[x][y]==1){
            q.push({{x,y},1});
        }
        if(grid[x][y]==2){
            q.push({{x,y},2});
        }
        if(grid[x][y]==3){
            q.push({{x,y},3});
        }
        if(grid[x][y]==4){
             q.push({{x,y},4});
        }
        if(grid[x][y]==5){
             q.push({{x,y},5});
        }
        if(grid[x][y]==6){
             q.push({{x,y},6});
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        map<pair<int,int>,int> umap;

       if(n==1 && m==1){
        return true;
       }

        if(grid[0][0]==1){
            q.push({{0,0},1});
        }
        if(grid[0][0]==2){
            q.push({{0,0},2});
        }
        if(grid[0][0]==3){
            q.push({{0,0},3});
        }
        if(grid[0][0]==4){
             q.push({{0,0},4});
        }
        if(grid[0][0]==5){
             q.push({{0,0},5});
        }
        if(grid[0][0]==6){
             q.push({{0,0},6});
        }
        umap[{0,0}]=1;
        while(!q.empty()){
            pair <pair<int,int>,int> p=q.front();
            int x=p.first.first;
            int y=p.first.second;
            int dir=p.second;
           
            q.pop();
            
            if(dir==2){
                if(x-1>=0){

                   if(umap[{x-1,y}]==0){
                    if(grid[x-1][y]==3 || grid[x-1][y]==4 || grid[x-1][y]==2){
                      check(x-1,y,grid);
                      umap[{x-1,y}]+=1;
                      if(x-1==n-1 && y==m-1){
                        return true;
                      }
                   }}
                }
                if(x+1<n){
                     if(umap[{x+1,y}]==0){

                    if(grid[x+1][y]==5 || grid[x+1][y]==6 || grid[x+1][y]==2){
                      check(x+1,y,grid);
                      umap[{x+1,y}]=1;
                      if(x+1==n-1 && y==m-1){
                        return true;
                      }}
                   }
                }
            }
            else if(dir==1){
                  if(y-1>=0){
                   if(umap[{x,y-1}]==0){
                    if(grid[x][y-1]==4 || grid[x][y-1]==6 || grid[x][y-1]==1){
                      check(x,y-1,grid);
                      umap[{x,y-1}]=1;
                      if(x==n-1 && y-1==m-1){
                        return true;
                      }}
                   }
                }
                if(y+1<m){
                     if(umap[{x,y+1}]==0){
                      if(grid[x][y+1]==5 || grid[x][y+1]==3 || grid[x][y+1]==1){  
                      check(x,y+1,grid);
                      umap[{x,y+1}]=1;
                      if(x==n-1 && y+1==m-1){
                        return true;
                      }}
                   }
                }
            }
            else if(dir==3){
                if(y-1>=0){
                 
                   if(umap[{x,y-1}]==0){
                   if(grid[x][y-1]==4 || grid[x][y-1]==6 || grid[x][y-1]==1){
                      check(x,y-1,grid);
                      umap[{x,y-1}]=1;
                      if(x==n-1 && y-1==m-1){
                        return true;
                      }
                   }}
                }
                 if(x+1<n){
                     if(umap[{x+1,y}]==0){
                         if(grid[x+1][y]==5 || grid[x+1][y]==6 || grid[x+1][y]==2){
                      check(x+1,y,grid);
                      umap[{x+1,y}]=1;
                       if(x+1==n-1 && y==m-1){
                        return true;
                      }}
                   }
                }
                 
            }
            else if(dir==4){
                if(x+1<n){
                     if(umap[{x+1,y}]==0){

                    if(grid[x+1][y]==6 || grid[x+1][y]==5 || grid[x+1][y]==2){
                      check(x+1,y,grid);
                      umap[{x+1,y}]=1;
                       if(x+1==n-1 && y==m-1){
                        return true;
                      }}
                   }
                }
                 if(y+1<m){
                     if(umap[{x,y+1}]==0){

                     if(grid[x][y+1]==3 || grid[x][y+1]==5 || grid[x][y+1]==1){
                      check(x,y+1,grid);
                      umap[{x,y+1}]=1;
                      if(x==n-1 && y+1==m-1){
                        return true;
                      }}
                   }
                }


            }
            else if(dir==5){
if(x-1>=0){
                   if(umap[{x-1,y}]==0){
                     if(grid[x-1][y]==3 || grid[x-1][y]==4 || grid[x-1][y]==2){
                      check(x-1,y,grid);
                      umap[{x-1,y}]=1;
                      if(x-1==n-1 && y==m-1){
                        return true;
                      }
                   }}
                }
                 if(y-1>=0){
                   if(umap[{x,y-1}]==0){
                     if(grid[x][y-1]==4 || grid[x][y-1]==6 || grid[x][y-1]==1){
                      check(x,y-1,grid);
                      umap[{x,y-1}]=1;
                      if(x==n-1 && y-1==m-1){
                        return true;
                      }
                   }}
                }

            }
            else if(dir==6){
                 if(x-1>=0){
                     if(umap[{x-1,y}]==0){
                         if(grid[x-1][y]==4 || grid[x-1][y]==6 || grid[x-1][y]==2){
                      check(x-1,y,grid);
                      umap[{x-1,y}]=1;
                      if(x-1==n-1 && y==m-1){
                        return true;
                      }}
                   }
                }
                if(y+1<m){
                   if(umap[{x,y+1}]==0){
                    if(grid[x][y+1]==5 || grid[x][y+1]==3 || grid[x][y+1]==1){
                      check(x,y+1,grid);
                      umap[{x,y+1}]=1;
                      if(x==n-1 && y+1==m-1){
                        return true;
                      }
                   }}
                }

                 
            }


        }

        return false;
    }
};