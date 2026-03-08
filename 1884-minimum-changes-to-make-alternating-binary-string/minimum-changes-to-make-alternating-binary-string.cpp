class Solution {
public:
    int minOperations(string s) {
        
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
               if(s[i]=='1'){
                   cnt1+=1;
               }
               else{
cnt2+=1;
               }
            }
            else{
                if(s[i]=='0'){
    cnt1+=1;
                }
                else{
cnt2+=1;
                }
            }
            cout<<cnt1;
            cout<<" ";
            cout<<cnt2;
            cout<<"\n";
        }

        return min(cnt1,cnt2);
    }
};