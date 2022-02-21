class Solution {
public:
    int countEven(int num) {
         int ans=0;
        for(int i=1;i<=num;i++){
            string st=to_string(i);
            int sum=0;
            for(int j=0;j<st.size();j++){
                sum+=(st[j]-'0');
            }
            if(sum%2==0){
                ans+=1;
            }
        }
        return ans;
    }
};