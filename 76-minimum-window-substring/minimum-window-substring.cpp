class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(128, 0);
        int cnt=0;
        for (char c : t) {
            v[c]++;
            cnt+=1;
        }
        vector<int> v1=v;
        int i=0;
        int j=0;
        int sz=-1;
        string ans="";
        int st=-1;
        int end=-1;
        while(j<s.size()){
            if(v[s[j]]>0){
                v[s[j]]-=1;
                cnt-=1;
                if(cnt==0){
                   
                    if(sz==-1){
                        sz=(j-i+1);
                        st=i;
                        end=j;
                    }
                    else if(j-i+1 <sz){
                        sz=j-i+1;
                        st=i;
                        end=j;
                    }
                  
                }
                while(cnt==0){
                    if(v1[s[i]]>0){
                        v[s[i]]+=1;
                        if(v[s[i]]>0){
                        cnt+=1;}
                        i+=1;
                    }
                    else{
                        i+=1;
                    }
                     if(cnt==0){
                       
                        if(sz==-1){
                             sz=(j-i+1);
                        st=i;
                        end=j;
                    }
                    else if(j-i+1 <sz){
                         sz=(j-i+1);
                       st=i;
                        end=j;
                    }
                    }
                }
               
            }
            else{
                v[s[j]]-=1;
            }
j+=1;
        }
      
        if(st==-1){
            return ans;
        }
        ans=s.substr(st,(end-st+1));

        return ans;
    }
};