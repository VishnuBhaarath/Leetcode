class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();

        vector<int> v(n+1,0);

        for(int i=n-1;i>=0;i--){
             int sum=digits[i]+carry;
             if(i== n-1){
                sum+=1;
             }
             if(sum>=10){
                carry=1;

             }
             else{
                carry=0;
             }
             v[i+1]=sum%10;
        }
        if(carry!=0){
            v[0]=carry;
        }
        vector<int> v1;
        if(v[0]!=0){
            v1.push_back(v[0]);
        }
        for(int i=1;i<v.size();i++){
            
                v1.push_back(v[i]);
            

        }
        return v1;

    }
};