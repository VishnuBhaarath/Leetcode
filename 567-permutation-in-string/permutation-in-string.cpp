class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26,0);
        for(int i=0;i<s1.size();i++){
            v[s1[i]-'a']+=1;
        }
        int n=s2.size();
        int j=0;
        int i=0;
        int cnt=0;
        while(j<s2.size()){
            cout<<s2[j];
            cout<<" ";
            if(v[s2[j]-'a']>0){
                cout<<"loop1";
                cout<<" ";
                v[s2[j]-'a']-=1;
                cnt+=1;
                if(cnt==s1.size()){
                    return true;
                }
                j+=1;
            }
            else{
               while(s2[i]!=s2[j]){
                  v[s2[i]-'a']+=1;
                  i+=1;
                  cnt-=1;
                  if(i>=j){
                     break;
                  }
               }
               if(i>=j){
                 j+=1;
                 i=j;
                 cnt=0;
                 //cnt=1;
               }
               else{
                 v[s2[i]-'a']-=1;
                 cnt-=1;
                 v[s2[j]-'a']+=1;
                 cnt+=1;
                 if(cnt==s1.size()){
                    return true;
                }
                i+=1;
                 j+=1;
               }

            }
            cout<<i;
            cout<<" ";
            cout<<j;
            cout<<" ";
            cout<<cnt;
            cout<<"\n";
           // j+=1;
        }
        return false;
    }
};