class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        
         map<string,vector<string>> umap;
         for(int i=0;i<wordList.size();i++){
            string str=wordList[i];
            int cnt=0;
            for(int j=0;j<str.size();j++){
                if(beginWord[j]!=str[j]){
                    cnt+=1;
                }
                if(cnt>1){
                    break;
                }
            }
            if(cnt==1){
                umap[beginWord].push_back(str);
            }
         }

         for(int i=0;i<wordList.size();i++){
            string str1=wordList[i];
            for(int j=i+1;j<wordList.size();j++){
                string str2=wordList[j];
                int cnt=0;
                for(int k=0;k<str1.size();k++){
                    if(str1[k]!=str2[k]){
                        cnt+=1;
                    }
                    if(cnt>1){
                    break;
                }
                }
                if(cnt==1){
                      umap[str1].push_back(str2);
            umap[str2].push_back(str1);
                }
            }
           
         }
   
        queue<string> q;
        q.push(beginWord);
        map<string,int> umap1;
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            cnt+=1;
            while(sz>0){
                string st=q.front();
                umap1[st]+=1;
              
                q.pop();
                vector<string> v= umap[st];
                for(int j=0;j<v.size();j++){
                    if(umap1[v[j]]==0){
                        q.push(v[j]);
                    }
                    if(v[j]==endWord){
                        cnt+=1;
                        return cnt;
                    }
                }
                sz-=1;
            }
        
        }

         return 0;

     }
};