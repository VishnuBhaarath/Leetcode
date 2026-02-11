class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1;
        int b=-1;
        int c=-1;
        int cnt=0;
        for(int i=0;i<s.size();i++){
             if(s[i]=='a'){
                 a=i;
             }
             if(s[i]=='b'){
                b=i;
             }
             if(s[i]=='c'){
                c=i;
             }
             if(a!=-1 && b!=-1 && c!=-1){
                break;
             }
        }
        if(a==-1 || b==-1 || c==-1){
            return cnt;
        }
        for(int i=0;i<s.size();i++){
             if(s[i]=='a'){
                if(b==-1 || c==-1){
                    return cnt;
                }
                int val=max(b,c);
                cnt+=(s.size()-val);
                if(a==i){
                     for(int j=i+1;j<s.size();j++){
                         if(s[j]=='a'){
                            a=j;
                            break;
                         }
                     }
                     if(a==i){
                        a=-1;
                     }
                }
             }
             else if(s[i]=='b'){
                if(a==-1 || c==-1){
                    return cnt;
                }
                int val=max(a,c);
                cnt+=(s.size()-val);
                if(b==i){
                     for(int j=i+1;j<s.size();j++){
                         if(s[j]=='b'){
                            b=j;
                            break;
                         }
                     }
                     if(b==i){
                        b=-1;
                     }
                }
             }
             else if(s[i]=='c'){
                 if(a==-1 || b==-1){
                    return cnt;
                 }
                 int val=max(a,b);
                 cnt+=(s.size()-val);
                 if(c==i){
                     for(int j=i+1;j<s.size();j++){
                         if(s[j]=='c'){
                            c=j;
                            break;
                         }
                     }
                     if(c==i){
                        c=-1;
                     }
                 }

                 }
             cout<<cnt;
             cout<<"\n";
        }
        return cnt;
    }
};