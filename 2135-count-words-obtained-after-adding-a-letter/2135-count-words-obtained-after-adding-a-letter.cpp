class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        map<string,int> umap;
        for(int i=0;i<startWords.size();i++){
            sort(startWords[i].begin(),startWords[i].end());
            umap[startWords[i]]+=1;
        }
        int ans=0;
        for(int i=0;i<targetWords.size();i++){
            sort(targetWords[i].begin(),targetWords[i].end());
            string temp=targetWords[i];
           
            for(int j=0;j<temp.size();j++){
                string st1=temp.substr(0,j);
                string st2=temp.substr(j+1,temp.size()-j);
                string st=st1+st2;
                if(umap[st]!=0){
                    ans+=1;
                    break;
                }
            }
          
        }
        return ans;
    }
};