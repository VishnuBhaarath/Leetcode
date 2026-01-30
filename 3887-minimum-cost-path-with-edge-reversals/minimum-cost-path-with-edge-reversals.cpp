class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> umap;
        map<pair<int,int>,int> umap1;
         map<pair<int,int>,int> umap2;
        for(int i=0;i<edges.size();i++){
            umap[edges[i][0]].push_back(edges[i][1]);
            umap[edges[i][1]].push_back(edges[i][0]);
            if(umap2[{edges[i][0],edges[i][1]}]==0){
            umap1[{edges[i][0],edges[i][1]}]=edges[i][2];
            umap2[{edges[i][0],edges[i][1]}]+=1;
            }
            else{
                umap1[{edges[i][0],edges[i][1]}]=min(umap1[{edges[i][0],edges[i][1]}],edges[i][2]);
            }
            if(umap2[{edges[i][1],edges[i][0]}]==0){
                 umap1[{edges[i][1],edges[i][0]}]=2*edges[i][2];
                 umap2[{edges[i][1],edges[i][0]}]+=1;
            }
            else{
                umap1[{edges[i][1],edges[i][0]}]=min(umap1[{edges[i][1],edges[i][0]}],2*edges[i][2]);
            }

        }
        vector<long long int> v(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        v[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int> tp=pq.top();
            pq.pop();
            if(tp.second ==n-1){
                return v[n-1];
            }
            vector<int> v1=umap[tp.second];
            for(int i=0;i<v1.size();i++){
                long long int c1=v[v1[i]];
                long long int c2=v[tp.second] + umap1[{tp.second,v1[i]}];
                if(c2<c1){
                    v[v1[i]]=c2;
                    pq.push({c2,v1[i]});
                }
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            cout<<" ";
        }
        cout<<"\n";
        if(v[n-1]==INT_MAX){
            return -1;
        }
        return v[n-1];
    }
};