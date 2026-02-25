class Solution {
public:
    int swimInWater(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        map<pair<int,int>,int> umap;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

vector<int> r={1,-1,0,0};
vector<int> c={0,0,1,-1};
 pq.push({heights[0][0], {0, 0}});
int ans=heights[0][0];
 while(!pq.empty()){
      pair<int, pair<int, int>> p=pq.top();
      pq.pop();
      int i=p.second.first;
      int j=p.second.second;
      int val=p.first;
      ans=max(ans,val);
      umap[{i,j}]=1;
     
      if(i==n-1 && j==m-1){
        return ans;
      }
      
     
      

      for(int k=0;k<4;k++){
          int x=i+r[k];
          int y=j+c[k];

          if((x>=0 && x<n) && (y>=0 && y<m)){
               if(umap[{x,y}]==0){
                  
                    umap[{x,y}]=1;
                   int cost=max(val,heights[x][y]);

                   pq.push({cost,{x,y}});
               }
          }
      }

    
 }

        return ans;
    }
};