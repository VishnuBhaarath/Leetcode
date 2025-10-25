class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        map<char,int> umap;
        map<char,int> umap1;
        for(int i=0;i<t.size();i++){
            umap1[t[i]]+=1;
        }

        int i=0;
        int j=0;
        int idx1=0;
        int ans=0;
        int l=-1;
        int r=-1;
        while(j<s.size()){
          if(umap[s[j]]<umap1[s[j]]){
             umap[s[j]]+=1;
             idx1+=1;
             if(idx1==m){
                int sz=j-i+1;
                if(ans==0){
                    ans=sz;
                    l=i;
                    r=j;
                }
                else if(sz<ans){
                    ans=sz;
                    l=i;
                    r=j;
                }
             }
             while(umap[s[i]]>umap1[s[i]]){
             
                umap[s[i]]-=1;
                   i+=1;
             }
             if(idx1==m){
                int sz=j-i+1;
                if(ans==0){
                    ans=sz;
                    l=i;
                    r=j;
                }
                else if(sz<ans){
                    ans=sz;
                    l=i;
                    r=j;
                }

             }
          }
          else{
            umap[s[j]]+=1;
            while(umap[s[i]]>umap1[s[i]]){
              
                umap[s[i]]-=1;
                  i+=1;
             }
                 if(idx1==m){
                int sz=j-i+1;
                if(ans==0){
                    ans=sz;
                    l=i;
                    r=j;
                }
                else if(sz<ans){
                    ans=sz;
                    l=i;
                    r=j;
                }

             }
             
          }
          
          j+=1;
        }
       
        string st="";
        if(l==-1){
            return st;
        }
        for(int i=l;i<=r;i++){
            st+=s[i];
        }
        return st;
    }
};