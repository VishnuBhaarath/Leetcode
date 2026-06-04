class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            string st=to_string(i);
            for(int j=1;j<st.size()-1;j++){
                 if(st[j]>st[j-1] && st[j]>st[j+1]){
                    cnt+=1;
                 }
                 if(st[j]<st[j-1] && st[j]<st[j+1]){
                    cnt+=1;
                 }
            }

        }
        return cnt;
    }
};