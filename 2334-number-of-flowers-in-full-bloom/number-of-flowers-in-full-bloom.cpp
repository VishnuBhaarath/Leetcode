class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> umap;
        for(int i=0;i<flowers.size();i++){
            umap[flowers[i][0]]+=1;
            umap[flowers[i][1]+1]-=1;
        }
        map<int,int> umap2;
        vector<int> v;
        for(int i=0;i<people.size();i++){
            if(umap2[people[i]]==0){
                v.push_back(people[i]);
                
            }
            umap2[people[i]]+=1;
        }
        sort(v.begin(),v.end());
        
        map<int,int> umap1;
        int j=0;
        int cnt=0;
        for(auto x:umap){
            if(j<v.size()){
            while(x.first>v[j]){
                umap1[v[j]]=cnt;
                j+=1;
                if(j==v.size()){
                    break;
                }
            }}
            cnt+=x.second;
            if(j<v.size()){
            while(x.first==v[j]){
                umap1[v[j]]=cnt;
                j+=1;
                if(j==v.size()){
                    break;
                }
            }}

        }

    
       
        vector<int> ans;
        for(int i=0;i<people.size();i++){
            ans.push_back(umap1[people[i]]);
        }
        return ans;
    }
};