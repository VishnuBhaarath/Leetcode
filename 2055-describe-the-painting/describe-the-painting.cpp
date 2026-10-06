class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        map<long long int,long long int> umap;
        vector<vector<long long>> v;
        for(int i=0;i<segments.size();i++){
            //v[segments[i][0]]+=segments[i][2];
           // v[segments[i][1]+1]-=segments[i][2];
            umap[segments[i][0]]+=segments[i][2];
            umap[segments[i][1]]-=segments[i][2];
        }
        long long int st=-1;
        long long int val=0;
        for(auto x:umap){
           
            if(st==-1){
                st=x.first;
                val+=x.second;
            }
            else{
                
                if(val!=0)
                v.push_back({st,x.first,val});
                val+=x.second;
                st=x.first;
                
            }
            
        }
        return v;
    }
};