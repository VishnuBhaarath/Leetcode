class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
          vector<string> ans;
        map<string,int> umap;
        map<string,int> umap1;
        for(int i=0;i<s.size();i++){
         
            if(umap[s.substr(i,10)]!=0){
                if(umap1[s.substr(i,10)]==0){
                ans.push_back(s.substr(i,10));
                    umap1[s.substr(i,10)]+=1;
                }
            }
            umap[s.substr(i,10)]+=1;
        
        }
       
        return ans;
    }
};