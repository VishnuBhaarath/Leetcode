class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<pair<int,int>,int> umap;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    if(umap[{i,j}]==0){
                        queue<pair<int,int>> q;
                        umap[{i,j}]+=1;
                        q.push({i,j});
                        cnt+=1;
                        while(!q.empty()){
                            int k=q.front().first;
                            int l=q.front().second;
                             q.pop();

                            int a=k;
                            int b=l;
                            while(a>=0){
                                if(grid[a][b]=='1'){
                                    if(umap[{a,b}]==0){
                                        q.push({a,b});
                                        umap[{a,b}]+=1;
                                    }
                                }
                                else{
                                    break;
                                }
                                a-=1;
                            }
                            a=k;
                            while(a<n){
                                if(grid[a][b]=='1'){
                                    if(umap[{a,b}]==0){
                                        q.push({a,b});
                                        umap[{a,b}]+=1;
                                    }
                                }
                                else{
                                    break;
                                }
                                a+=1;
                            }
                            a=k;
                            b=l;

                              while(b>=0){
                                if(grid[a][b]=='1'){
                                    if(umap[{a,b}]==0){
                                        q.push({a,b});
                                        umap[{a,b}]+=1;
                                    }
                                }
                                else{
                                    break;
                                }
                                b-=1;
                            }
                            b=l;

                             while(b<m){
                                if(grid[a][b]=='1'){
                                    if(umap[{a,b}]==0){
                                        q.push({a,b});
                                        umap[{a,b}]+=1;
                                    }
                                }
                                else{
                                    break;
                                }
                                b+=1;
                            }
                           
                        }

                    }
                }
            }
        }

        return cnt;

    }
};