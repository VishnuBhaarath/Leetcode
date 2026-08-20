class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> umap;

        for(int i=0;i<t.size();i++){
            umap[t[i]]+=1;
        }
        int l=0;
        int r=0;
        int sz=-1;
int cnt=0;
        int st=0;
        int n=s.size();
        int m=t.size();

        while(r<n){
            
             umap[s[r]]-=1;
             if(umap[s[r]]>0){
                cnt+=1;
             }
             if(umap[s[r]]==0){
                cnt+=1;
                while(cnt==m){
                    if(sz==-1){
                        sz=(r-l+1);
                        st=l;
                    }
                    else{
                        if(r-l+1 < sz){
                            sz=r-l+1;
                            st=l;
                        }
                    }
                 
                    umap[s[l]]+=1;
                    if(umap[s[l]]>0){
                        cnt-=1;
                    }
                    l+=1;
                }
             }
             r+=1;
        }
     
        if(sz==-1){
            return "";
        }
        return s.substr(st,sz);
    }
};