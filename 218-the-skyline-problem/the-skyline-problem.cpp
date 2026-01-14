class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(),buildings.end());
        priority_queue<int> pq;
        multiset<int> heights;
        vector<vector<int>> v;
        for(int i=0;i<buildings.size();i++){
            v.push_back({buildings[i][0],buildings[i][2],1});
            v.push_back({buildings[i][1],buildings[i][2],-1});
        }
        sort(v.begin(),v.end());
        
        int prevx=-1;
        int prevh=-1;
        vector<vector<int>> ans;
        heights.insert(0); 
         int prevMaxHeight = 0;
        for(int i=0;i<v.size();i++){
           
             if(v[i][2]==1){
              
                heights.insert(v[i][1]);
             }
             else{

               
               heights.erase(heights.find(v[i][1]));
             }
            
            if(prevx==-1) {
                prevx=v[i][0];
                prevh=v[i][1];
                ans.push_back({prevx,prevh});
            }
            else{
                int n=ans.size();
                int h=ans[n-1][1];
                int x=ans[n-1][0];
                int currMaxHeight = *heights.rbegin(); 
                
                if(!heights.empty()){
                if(currMaxHeight != h){
                    ans.push_back({v[i][0],currMaxHeight});
                }}
                else{
                     ans.push_back({v[i][0],0});
                }
            }
          
        }

        vector<vector<int>> v1;
        int x0=ans[0][0];
        int y0=ans[0][1];
        for(int i=1;i<ans.size();i++){
          if(ans[i][0]!=x0){
            v1.push_back({x0,y0});
            x0=ans[i][0];
            y0=ans[i][1];
            }
          else{
               y0=max(y0,ans[i][1]);
          }
        }
        v1.push_back({x0,y0});

        vector<vector<int>> v2;
        x0=v1[0][0];
        y0=v1[0][1];
        for(int i=0;i<v1.size();i++){
            if(v1[i][1]!=y0){
                v2.push_back({x0,y0});
                x0=v1[i][0];
                y0=v1[i][1];
            }
        }
        v2.push_back({x0,y0});
         return v2;
    }
};