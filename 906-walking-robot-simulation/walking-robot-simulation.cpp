class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir=1;
        int x=0;
        int y=0;
        int dist=0;
        map<pair<int,int>,int> umap;
        for(int i=0;i<obstacles.size();i++){
             umap[{obstacles[i][0],obstacles[i][1]}]=1;
        }
        for(int i=0;i<commands.size();i++){
             if(commands[i]==-1){
                 if(dir==1){
                     dir=2;
                 }
                 else if(dir==2){
                    dir=3;
                 }
                 else if(dir==3){
                    dir=4;
                 }
                 else if(dir==4){
                    dir=1;
                 }
             }

             else if(commands[i]==-2){
if(dir==1){
                     dir=4;
                 }
                 else if(dir==2){
                    dir=1;
                 }
                 else if(dir==3){
                    dir=2;
                 }
                 else if(dir==4){
                    dir=3;
                 }
             }
             else{
                int k=commands[i];
                if(dir==1){
                     int i=0;
                     while(i<k){
                        
                         if(umap[{x,y+1}]==0){
                         y+=1; }
                         else{
                            break;
                         }
                         i+=1;
                     }
                }
                else if(dir==2){
                      int i=0;
                      while(i<k){
                         if(umap[{x+1,y}]==0){
                         x+=1; }
                         else{
                            break;
                         }
                         i+=1;
                     }

                }

                 else if(dir==3){
                      int i=0;
                      while(i<k){
                         if(umap[{x,y-1}]==0){
                         y-=1; }
                         else{
                            break;
                         }
                         i+=1;
                     }

                }

                 else if(dir==4){
                      int i=0;
                      while(i<k){
                        if(umap[{x-1,y}]==0){
                         x-=1; }
                         else{
                            break;
                         }
                         i+=1;
                     }

                }

             }
            
             int val=(x*x)+(y*y);
             dist=max(dist,val);
             cout<<"\n";
        }

      
        return dist;
    }
};