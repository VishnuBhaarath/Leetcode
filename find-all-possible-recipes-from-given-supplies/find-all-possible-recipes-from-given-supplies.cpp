class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<string>> umap;
        map<string ,int> umap1;
        for(int i=0;i<supplies.size();i++){
            umap1[supplies[i]]+=1;
        }
        map<string,int> deg;
        for(int i=0;i<ingredients.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(umap1[ingredients[i][j]]==0){
                    umap[ingredients[i][j]].push_back(recipes[i]);
                    deg[recipes[i]]+=1;
                }
            }
        }
         queue<string> q;
        for(auto x : recipes){
            if(deg[x]== 0){
                q.push(x);
            }
        }
        vector<string> ans;
        while(!q.empty()){
            int c = q.size();
            while(c != 0){
                string tmp = q.front();
                q.pop();
                ans.push_back(tmp);
                for(auto nbr : umap[tmp]){
                    deg[nbr]--;
                    if(deg[nbr] == 0)
                        q.push(nbr);
                }
                c--;
            }
        }
        return ans;
    }
};